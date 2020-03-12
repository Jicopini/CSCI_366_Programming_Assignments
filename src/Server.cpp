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
#include "Server.hpp"


/**
 * Calculate the length of a file (helper function)
 *
 * @param file - the file whose length we want to query
 * @return length of the file in bytes
 */
int get_file_length(ifstream *file){
    file->seekg (0, file->end);
    int length = file->tellg();
    file->seekg (0, file->beg);

    return length;
}


void Server::initialize(unsigned int board_size,
                        string p1_setup_board,
                        string p2_setup_board){

    this->p1_setup_board.open(p1_setup_board);
    this->p2_setup_board.open(p2_setup_board);
    this->board_size = board_size;


    int bSize = board_size;
    int size = (get_file_length(&this->p1_setup_board) - (bSize));
    bSize = bSize * bSize;
    if (bSize != size) {
        throw "Correct_Board_Size 1 Exception";
    }

    int bSize2 = board_size;
    int size2 = (get_file_length(&this->p2_setup_board) - (bSize2));
    bSize2 = bSize2 * bSize2;
    if (bSize2 != size2){
        throw "Correct_Board_Size 2 Exception";
    }

    if(board_size <= 0){
        throw "Wrong_Board_Size Exception";
    }
    if(p1_setup_board == "" || p2_setup_board == ""){
        throw "Bad_File_Name Exception";
    }
}


int Server::evaluate_shot(unsigned int player, unsigned int x, unsigned int y) {
    //Bad Player Number
    if (player > MAX_PLAYERS || player <= 0 ){
        throw "Bad_Player_Number Exception";
    }
    //Out of Bounds x and y
    if(x >= board_size || x < 0){
        return OUT_OF_BOUNDS;
    }
    if(y >= board_size || y < 0){
        return OUT_OF_BOUNDS;
    }
    if(x <= board_size-1 && y <= board_size-1){
    }
    else{
        throw "Max_Bounds Exception";
    }

    if(x >= board_size){
        return OUT_OF_BOUNDS;
    }
    if(y >= board_size){
        return OUT_OF_BOUNDS;
    }
    if(player == 2){
        int length = get_file_length(&p1_setup_board);
        char * buffer = new char [length];
        p1_setup_board.read(buffer,length);

        if (buffer[(y*board_size+1) + x] == '_'){
            return MISS;
        }
        else{
            return HIT;
        }
    }
    if(player == 1){
        int length = get_file_length(&p2_setup_board);
        char * buffer = new char [length];
        p2_setup_board.read(buffer,length);


        if (buffer[(y*board_size+1) + x] == '_'){
            return MISS;
        }
        else{
            return HIT;
        }
    }





}


int Server::process_shot(unsigned int player) {
    string file_name1 = "player_" + to_string(player) + ".shot.json";
    string file_name2 = "player_" + to_string(player) + ".result.json";
    unsigned int x = 2, y = 2;
    int result = 2;




    ifstream inFile(file_name1); // create an input file stream
    cereal::JSONInputArchive read_inFile(inFile); // initialize an archive on the file
    read_inFile(x,y);
    inFile.close();


    remove("player_1.shot.json");
    remove("player_2.shot.json");

    result = evaluate_shot(player, x, y);


    ofstream outFile(file_name2);
    cereal::JSONOutputArchive write_archive(outFile);
    write_archive(CEREAL_NVP(result));

    return NO_SHOT_FILE;
}