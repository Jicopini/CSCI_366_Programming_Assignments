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

void Client::initialize(unsigned int player, unsigned int board_size){
    // Initializing variables
    this->player = player;
    this->board_size = board_size;
    board_name = "player_" + to_string(player);
    string outFile = board_name + ".action_board.json";

    // Creates 2d vector for storage
    std::vector<std::vector<int> > board(this->board_size, std::vector<int>(this->board_size));

    //Writes to 2d vector for action board
    ofstream array_ofp(outFile);
    cereal::JSONOutputArchive write_archive(array_ofp);
    write_archive(CEREAL_NVP(board));

    initialized = true;

}

void Client::fire(unsigned int x, unsigned int y) {

    string file = board_name +".shot.json";

    //Writes shot to shot file
    ofstream outFile(file);
    cereal::JSONOutputArchive write_archive(outFile);
    write_archive(CEREAL_NVP(x), CEREAL_NVP(y));

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
    // Reads result file
    ifstream array_ifp(file);
    cereal::JSONInputArchive read_archive(array_ifp);
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

void Client::update_action_board(int result, unsigned int x, unsigned int y) {
    string file = board_name + ".action_board.json";

    //2d vector to store action board
    std::vector<std::vector<int> > matrix(this->board_size, std::vector<int>(this->board_size));

    //Writes to action board
    ifstream array_ifp(file);
    cereal::JSONInputArchive read_archive(array_ifp);
    read_archive(matrix);
    array_ifp.close();

    //Changes value of shot location
    matrix[x][y] = result;

    //writes new action board back to file
    ofstream array_ofp(file); // create an output file stream
    cereal::JSONOutputArchive write_archive(array_ofp); // initialize an archive on the file
    write_archive(cereal::make_nvp("board", matrix)); // serialize the data giving it a name

}


string Client::render_action_board(){
    string file = board_name + ".action_board.json";
    string output = "";

    //2d vector to store action board
    std::vector<std::vector<int> > matrix(this->board_size, std::vector<int>(this->board_size));

    // reads action board
    ifstream outFile(file);
    cereal::JSONInputArchive read_archive(outFile); // initialize an archive on the file
    read_archive(matrix);
    outFile.close();

    // Saves action board to string
    for(int i = 0; i < board_size; i++){
        for(int j = 0; j < board_size; j++){
            if(matrix[i][j] == 0){
                output = output + "_";
            }
            else {
                output = output + to_string(matrix[i][j]);
            }
        }
        output = output + "\n";
    }
    return output;
}