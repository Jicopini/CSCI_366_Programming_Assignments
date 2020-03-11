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

/* Missing:
 * Initialize:
 * p1_setup_board
 * p2_setup_board
 */
void Server::initialize(unsigned int board_size,
                        string p1_setup_board,
                        string p2_setup_board){

    this->p1_setup_board.open(p1_setup_board);
    this->p2_setup_board.open(p1_setup_board);

    int bSize = board_size;
    int size = (get_file_length(&this->p1_setup_board) - (2 * bSize));
    bSize = bSize * bSize;
    if (bSize != size) {
        throw "Correct_Board_Size 1 Exception";
    }

    int bSize2 = board_size;
    int size2 = (get_file_length(&this->p2_setup_board) - (2 * bSize2));
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

/* Missing:
 * Hit_Detected
 * Miss_Detected
 * Out_Of_Bounds_X
 * Out_Of_Bounds_Y
 * Max_In_Bounds
 * Bad_Player_Number_low
 * Bad_Player_Number_Low_High
 */
int Server::evaluate_shot(unsigned int player, unsigned int x, unsigned int y) {
}

/* Missing:
 * Hit_Detected
 * Miss_Detected
 * Out_Of_Bounds_X
 * Out_Of_Bounds_Y
 * Max_In_Bounds
 * Bad_Player_Number_low
 * Bad_Player_Number_Low_High
 */
int Server::process_shot(unsigned int player) {
    string file_name1 = "player_" + to_string(player) + ".shot.json";
    string file_name2 = "player_" + to_string(player) + ".result.json";
    unsigned int x, y;
    int result;

    ifstream inFile(file_name1); // create an input file stream
    //cereal::JSONInputArchive read_inFile(inFile); // initialize an archive on the file
    //read_inFile(CEREAL_NVP(x), CEREAL_NVP(y));
    inFile.close();

    remove("player_1.shot.json");
    remove("player_2.shot.json");

    //result = evaluate_shot(player, x, y);
    /*
    ofstream outFile(file_name2);
    cereal::JSONOutputArchive write_archive(outFile);
    write_archive(CEREAL_NVP(result));
    write_archive.finishNode();
    outFile.close();
     */

    return NO_SHOT_FILE;
}