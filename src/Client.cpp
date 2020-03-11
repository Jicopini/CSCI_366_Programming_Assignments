//    Battleship game assignment for MSU CSCI 366
//    Copyright (C) 2020    Mike P. Wittie
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include "common.hpp"
#include "Client.hpp"

Client::~Client() {
    //remove("player_1.action_board.json");
    //remove("player_2.action_board.json");
}


void Client::initialize(unsigned int player, unsigned int board_size){
    Client::player = player;
    Client::board_size = board_size;
    board_name = "player_" + to_string(player);
    string outFile = board_name + ".action_board.json";
    string inFile = board_name + ".setup_board.txt";


    std::vector<std::vector<int>> array1;
    array1.resize(board_size, std::vector<int>(Client::board_size, 0));

    ofstream array_ofp("player_1.action_board.json"); // create an output file stream
    cereal::JSONOutputArchive write_archive(array_ofp); // initialize an archive on the file
    write_archive(cereal::make_nvp("board", array1)); // serialize the data giving it a name
    //write_archive.finishNode(); // wait for the writing process to finish
    array_ofp.close(); // close the file

    initialized = true;
}


void Client::fire(unsigned int x, unsigned int y) {
    string file = board_name +".shot.json";
    ofstream outFile(file);
    cereal::JSONOutputArchive write_archive(outFile);
    write_archive(CEREAL_NVP(x), CEREAL_NVP(y));
    write_archive.finishNode();
    outFile.close();

    cout << "Shot fired at: (" + to_string(x) + "," + to_string(y) + ")";
}


bool Client::result_available() {
    string fname = board_name + ".result.json";
    ifstream f(fname.c_str());
    if (f){
        return true;
    }
}


int Client::get_result() {
    string file = board_name + ".result.json";
    int result;
    ifstream array_ifp(file); // create an input file stream
    cereal::JSONInputArchive read_archive(array_ifp); // initialize an archive on the file
    read_archive(CEREAL_NVP(result));
    array_ifp.close();

    remove("player_1.result.json");
    remove("player_2.result.json");

    if (result == HIT){
        return HIT;
    }
    else if(result == MISS){
        return MISS;
    }
    else if(result == OUT_OF_BOUNDS){
        return OUT_OF_BOUNDS;
    }
    else{
        throw "Catch_Bad_Result Exception";
    }
}



/* Missing:
 * Updates the internal representation of player_#.action_board.json on the result of a shot.
 * Record_Hit
 * Record_Miss
 */
void Client::update_action_board(int result, unsigned int x, unsigned int y) {
    string file = board_name + ".action_board.json";
    std::vector<std::vector<int>> array_in;
    array_in.resize(board_size, std::vector<int>(board_size, 0));
    ifstream array_ifp(file); // create an input file stream
    cereal::JSONInputArchive read_archive(array_ifp); // initialize an archive on the file
    read_archive(array_in);
    array_ifp.close();

    array_in[x][y] = result;

    ofstream array_ofp(file); // create an output file stream
    cereal::JSONOutputArchive write_archive(array_ofp); // initialize an archive on the file
    write_archive(cereal::make_nvp("board", array_in)); // serialize the data giving it a name
    write_archive.finishNode(); // wait for the writing process to finish
    array_ofp.close(); // close the file

}

/* Missing:
 * Formats a string representing player_#.action_board.json as ASCII
 */
string Client::render_action_board(){
}