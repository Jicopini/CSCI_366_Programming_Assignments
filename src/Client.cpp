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
    remove("player_1.action_board.json");
    remove("player_2.action_board.json");
}

    //Done
void Client::initialize(unsigned int player, unsigned int board_size){

    this->player = player;
    this->board_size = board_size;
    board_name = "player_" + to_string(Client::player);
    string outFile = board_name + ".action_board.json";


    std::vector<std::vector<int> > board(this->board_size, std::vector<int>(this->board_size));

    ofstream array_ofp(outFile); // create an output file stream
    cereal::JSONOutputArchive write_archive(array_ofp); // initialize an archive on the file
    write_archive(CEREAL_NVP(board)); // serialize the data giving it a name

    initialized = true;

}

    //Done
void Client::fire(unsigned int x, unsigned int y) {

    string file = board_name +".shot.json";

    ofstream outFile(file);
    cereal::JSONOutputArchive write_archive(outFile);
    write_archive(CEREAL_NVP(x), CEREAL_NVP(y));
    //write_archive.finishNode();
    //outFile.close();

    cout << "Shot fired at: (" + to_string(x) + "," + to_string(y) + ")\n";

}

    //Done
bool Client::result_available() {
    string fname = board_name + ".result.json";
    ifstream f(fname.c_str());
    if (f){
        return true;
    }
}

    //Done
int Client::get_result() {
    string file = board_name + ".result.json";
    int result;
    ifstream array_ifp(file); // create an input file stream
    cereal::JSONInputArchive read_archive(array_ifp); // initialize an archive on the file
    read_archive(result);
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

    //Done
void Client::update_action_board(int result, unsigned int x, unsigned int y) {
    string file = board_name + ".action_board.json";

    std::vector<std::vector<int> > matrix(this->board_size, std::vector<int>(this->board_size));

    ifstream array_ifp(file); // create an input file stream
    cereal::JSONInputArchive read_archive(array_ifp); // initialize an archive on the file
    read_archive(matrix);
    array_ifp.close();

    matrix[x][y] = result;

    ofstream array_ofp(file); // create an output file stream
    cereal::JSONOutputArchive write_archive(array_ofp); // initialize an archive on the file
    write_archive(cereal::make_nvp("board", matrix)); // serialize the data giving it a name

}

/* Missing:
 * Formats a string representing player_#.action_board.json as ASCII
 */
string Client::render_action_board(){
    string file = board_name + ".action_board.json";
    /*
    string output;

    ifstream outFile(file);
    cereal::JSONInputArchive read_archive(outFile); // initialize an archive on the file
    read_archive(output);
    outFile.close();
    */
}