/*
    program: this is the connect-4 game, in order to win you need to connect 4 game pieces vertically,
    horizontally or diagonally.
    author: Zeyad Mohamed Arafat, 20230161.
    date: 1/3/2024.
    version: 1.4.
*/
// ====================================================================================================================================
#include <iostream>
#include <vector>
using namespace std;

// this function is used to display the game board after every play.
void print_game_board(string game_board[7][7]){
    int rows = 7;
    int column = 7;
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < rows ; j++){
        cout << game_board[i][j] << "     ";
        }
        cout << endl << endl;
    }
    return ;
}

// this function is used to check the validity of each move.
bool is_valid(vector<string> valid_moves, string player_move){
    int range = valid_moves.size() ;
    for (int i = 0 ; i < range ; i++){
        if (player_move == valid_moves[i]){
            return true;
        }
    }
    return false;
}

// this is the main one because it searches if there is a winner after each move.
int is_winner(string game_board[7][7]){
    // we start by creating counters and when one of them reaches 4 we know that there is a winner.
    int X_counter = 0 ;
    int O_counter = 0 ;
    // this for loop checks all the horizontal possibilities of connecting four pieces.
    for(int i = 0 ; i < 7 ; i++){
        for(int j = 0 ; j < 7 ; j++){// the nested for loop will check each horizontal line.
            if(game_board[i][j] == "X"){// if it finds X it increments the X_counter and resets the O_counter.
                X_counter++ ;
                O_counter = 0 ;
                if(X_counter == 4)return 1 ;
            }
            else if(game_board[i][j] == "O"){// if it finds O it increments the O_counter and resets the X_counter.
                O_counter++ ;
                X_counter = 0 ;
                if(O_counter == 4)return 2 ;
            }
            else{
                X_counter = 0;
                O_counter = 0;
            }

        }
    }

    // after each loop we need reset the counters.
    X_counter = 0 ;
    O_counter = 0 ;

    // this loop checks all the vertical possibilities with the same logic as the previous one.
    for(int i = 0 ; i < 7 ; i++){
        for(int j = 0 ; j < 7 ; j++){
            if(game_board[j][i] == "X"){
                X_counter++ ;
                O_counter = 0 ;
                if(X_counter == 4)return 1 ;
            }
            else if(game_board[j][i] == "O"){
                O_counter++ ;
                X_counter = 0 ;
                if(O_counter == 4)return 2 ;
            }
             else{
                X_counter = 0;
                O_counter = 0;
            }
        }
    }


    X_counter = 0 ;
    O_counter = 0 ;

    // each of the following loops will check the diagonal possibilities.(I didn't find a more optimal way)
    // all of the loops use the same logic as before.
    // to further understand each loop draw the game board.
    for(int i = 0 ; i < 7 ; i++){
        if(game_board[i][i] == "X"){
            X_counter++ ;
            O_counter = 0 ;
            if(X_counter == 4)return 1 ;
        }
        else if(game_board[i][i] == "O"){
            O_counter++ ;
            X_counter = 0 ;
            if(O_counter == 4)return 2 ;
        }
        else{
            X_counter = 0 ;
            O_counter = 0 ;
        }
    }


     X_counter = 0 ;
     O_counter = 0 ;


        for(int i = 0 ; i < 7 ; i++){
        if(game_board[i][6-i] == "X"){
            X_counter++ ;
            O_counter = 0 ;
            if(X_counter == 4)return 1 ;
        }
        else if(game_board[i][6-i] == "O"){
            O_counter++ ;
            X_counter = 0 ;
            if(O_counter == 4)return 2 ;
        }
        else{
            X_counter = 0 ;
            O_counter = 0 ;
        }
    }


     X_counter = 0 ;
     O_counter = 0 ;


        for(int i = 0 ; i < 6 ; i++){
        if(game_board[i][i+1] == "X"){
            X_counter++ ;
            O_counter = 0 ;
            if(X_counter == 4)return 1 ;
        }
        else if(game_board[i][i+1] == "O"){
            O_counter++ ;
            X_counter = 0 ;
            if(O_counter == 4)return 2 ;
        }
        else{
            X_counter = 0 ;
            O_counter = 0 ;
        }
    }


     X_counter = 0 ;
     O_counter = 0 ;


        for(int i = 0 ; i < 5 ; i++){
        if(game_board[i][i+2] == "X"){
            X_counter++ ;
            O_counter = 0 ;
            if(X_counter == 4)return 1 ;
        }
        else if(game_board[i][i+2] == "O"){
            O_counter++ ;
            X_counter = 0 ;
            if(O_counter == 4)return 2 ;
        }
        else{
            X_counter = 0 ;
            O_counter = 0 ;
        }
    }


     X_counter = 0 ;
     O_counter = 0 ;


    for(int i = 0 ; i < 4 ; i++){
        if(game_board[i][i+3] == "X"){
            X_counter++ ;
            O_counter = 0 ;
            if(X_counter == 4)return 1 ;
        }
        else if(game_board[i][i+3] == "O"){
            O_counter++ ;
            X_counter = 0 ;
            if(O_counter == 4)return 2 ;
        }
        else{
            X_counter = 0 ;
            O_counter = 0 ;
        }
    }


     X_counter = 0 ;
     O_counter = 0 ;


    for(int i = 1 ; i < 7 ; i++){
        if(game_board[i][i-1] == "X"){
            X_counter++ ;
            O_counter = 0 ;
            if(X_counter == 4)return 1 ;
        }
        else if(game_board[i][i-1] == "O"){
            O_counter++ ;
            X_counter = 0 ;
            if(O_counter == 4)return 2 ;
        }
        else{
            X_counter = 0 ;
            O_counter = 0 ;
        }
    }


     X_counter = 0 ;
     O_counter = 0 ;


    for(int i = 2 ; i < 7 ; i++){
        if(game_board[i][i-2] == "X"){
            X_counter++ ;
            O_counter = 0 ;
            if(X_counter == 4)return 1 ;
        }
        else if(game_board[i][i-2] == "O"){
            O_counter++ ;
            X_counter = 0 ;
            if(O_counter == 4)return 2 ;
        }
        else{
            X_counter = 0 ;
            O_counter = 0 ;
        }
    }


     X_counter = 0 ;
     O_counter = 0 ;


    for(int i = 0 ; i < 6 ; i++){
        if(game_board[i][5-i] == "X"){
            X_counter++ ;
            O_counter = 0 ;
            if(X_counter == 4)return 1 ;
        }
        else if(game_board[i][5-i] == "O"){
            O_counter++ ;
            X_counter = 0 ;
            if(O_counter == 4)return 2 ;
        }
        else{
            X_counter = 0 ;
            O_counter = 0 ;
        }
    }


     X_counter = 0 ;
     O_counter = 0 ;


    for(int i = 0 ; i < 5 ; i++){
        if(game_board[i][4-i] == "X"){
            X_counter++ ;
            O_counter = 0 ;
            if(X_counter == 4)return 1 ;
        }
        else if(game_board[i][4-i] == "O"){
            O_counter++ ;
            X_counter = 0 ;
            if(O_counter == 4)return 2 ;
        }
        else{
            X_counter = 0 ;
            O_counter = 0 ;
        }
    }


     X_counter = 0 ;
     O_counter = 0 ;



    for(int i = 0 ; i < 4 ; i++){
        if(game_board[i][3-i] == "X"){
            X_counter++ ;
            O_counter = 0 ;
            if(X_counter == 4)return 1 ;
        }
        else if(game_board[i][3-1] == "O"){
            O_counter++ ;
            X_counter = 0 ;
            if(O_counter == 4)return 2 ;
        }
        else{
            X_counter = 0 ;
            O_counter = 0 ;
        }
    }


     X_counter = 0 ;
     O_counter = 0 ;


    for(int i = 1 ; i < 7 ; i++){
        if(game_board[i][7-i] == "X"){
            X_counter++ ;
            O_counter = 0 ;
            if(X_counter == 4)return 1 ;
        }
        else if(game_board[i][7-i] == "O"){
            O_counter++ ;
            X_counter = 0 ;
            if(O_counter == 4)return 2 ;
        }
        else{
            X_counter = 0 ;
            O_counter = 0 ;
        }
    }


     X_counter = 0 ;
     O_counter = 0 ;



    for(int i = 2 ; i < 7 ; i++){
        if(game_board[i][8-i] == "X"){
            X_counter++ ;
            O_counter = 0 ;
            if(X_counter == 4)return 1 ;
        }
        else if(game_board[i][8-i] == "O"){
            O_counter++ ;
            X_counter = 0 ;
            if(O_counter == 4)return 2 ;
        }
        else{
            X_counter = 0 ;
            O_counter = 0 ;
        }
    }
    // this loop check if there is a draw.
    int counter = 0;
    for(int i = 0 ; i < 7 ; i++){
        if (game_board[0][i] == "-"){
            return 0;
        }
        else counter++ ;
        if(counter == 7) return 3;
    }


    return 0 ;
}

int main(){
    // we will start by setting the game storage.
    string game_board[7][7] ={"-" , "-" , "-" , "-" , "-" , "-" , "-",
                              "-" , "-" , "-" , "-" , "-" , "-" , "-",
                              "-" , "-" , "-" , "-" , "-" , "-" , "-",
                              "-" , "-" , "-" , "-" , "-" , "-" , "-",
                              "-" , "-" , "-" , "-" , "-" , "-" , "-",
                              "-" , "-" , "-" , "-" , "-" , "-" , "-",
                              "1" , "2" , "3" , "4" , "5" , "6" , "7"};
    string first_player_move, second_player_move;
    vector<string> valid_moves = {"1", "2", "3", "4", "5", "6", "7"} ;
    int row1_counter = 5 ;
    int row2_counter = 5 ;
    int row3_counter = 5 ;
    int row4_counter = 5 ;
    int row5_counter = 5 ;
    int row6_counter = 5 ;
    int row7_counter = 5 ;

    // explaining the game.
    cout << "this is the connect-4 game, in order to win you need to connect 4 game pieces vertically," << endl;
    cout << "horizontally or diagonally." << endl << endl << endl;
    print_game_board(game_board);

    // the begining of the game.
    // first loop to keep the game going until one of the players win.
    while (true){
            // the same logic applies for the other loop.
        while (true){// a loop to get the first player move(if the move is not valid the player will be asked to enter another move)
            cout << "enter first player move: " ;
            cin >> first_player_move ;
            cout << endl << endl ;
                if (is_valid(valid_moves, first_player_move)){// checking the validity of the move.
                    if (first_player_move == "1"){
                        game_board[row1_counter][0] = "X" ;// adding the piece to the bottom of the chosen column
                        row1_counter-- ;
                        if (row1_counter == -1) valid_moves[0] = "0";// if the column is full we remove it from the valid moves.
                        }
                        // the same logic applies for all the conditions.
                    else if (first_player_move == "2"){
                        game_board[row2_counter][1] = "X";
                        row2_counter-- ;
                        if (row2_counter == -1) valid_moves[1] = "0";
                        }
                    else if (first_player_move == "3"){
                        game_board[row3_counter][2] = "X";
                        row3_counter-- ;
                        if (row3_counter == -1) valid_moves[2] = "0";
                        }
                    else if (first_player_move == "4"){
                        game_board[row4_counter][3] = "X";
                        row4_counter-- ;
                        if (row4_counter == -1) valid_moves[3] = "0";
                        }
                    else if (first_player_move == "5"){
                        game_board[row5_counter][4] = "X";
                        row5_counter-- ;
                        if (row5_counter == -1) valid_moves[4] = "0";
                        }
                    else if (first_player_move == "6"){
                        game_board[row6_counter][5] = "X";
                        row6_counter-- ;
                        if (row6_counter == -1) valid_moves[5] = "0";
                        }
                    else if (first_player_move == "7"){
                        game_board[row7_counter][6] = "X";
                        row7_counter-- ;
                        if (row7_counter == -1) valid_moves[6] = "0";
                        }
                    else if (first_player_move == "0"){
                        cout << "move is not valid" << endl << endl ;
                        continue ;
                    }
                    break;
                }
                else {
                    cout << "move is not valid" << endl << endl ;
                }
            }
        print_game_board(game_board);// displaying the game board after each move.
        if(is_winner(game_board) == 1){// checking if the player wins after his move.
            cout << "first player wins!" ;
            break ;
        }
        else if(is_winner(game_board) == 3){
            cout << "it's a draw" ;
            break;
        }
        while (true){
            cout << "enter second player move: " ;
            cin >> second_player_move ;
            cout << endl << endl ;
                if (is_valid(valid_moves, second_player_move)){
                    if (second_player_move == "1"){
                        game_board[row1_counter][0] = "O" ;
                        row1_counter-- ;
                        if (row1_counter == -1) valid_moves[0] = "0";
                        }
                    else if (second_player_move == "2"){
                        game_board[row2_counter][1] = "O";
                        row2_counter-- ;
                        if (row2_counter == -1) valid_moves[1] = "0";
                        }
                    else if (second_player_move == "3"){
                        game_board[row3_counter][2] = "O";
                        row3_counter-- ;
                        if (row3_counter == -1) valid_moves[2] = "0";
                        }
                    else if (second_player_move == "4"){
                        game_board[row4_counter][3] = "O";
                        row4_counter-- ;
                        if (row4_counter == -1) valid_moves[3] = "0";
                        }
                    else if (second_player_move == "5"){
                        game_board[row5_counter][4] = "O";
                        row5_counter-- ;
                        if (row5_counter == -1) valid_moves[4] = "0";
                        }
                    else if (second_player_move == "6"){
                        game_board[row6_counter][5] = "O";
                        row6_counter-- ;
                        if (row6_counter == -1) valid_moves[5] = "0";
                        }
                    else if (second_player_move == "7"){
                        game_board[row7_counter][6] = "O";
                        row7_counter-- ;
                        if (row7_counter == -1) valid_moves[6] = "0";
                        }
                    else if (second_player_move == "0"){
                        cout << "move is not valid" << endl << endl ;
                        continue ;
                    }
                    break;
                }
                else {
                    cout << "move is not valid" << endl << endl ;
                }
            }
        print_game_board(game_board); // displaying the game board after each move.
        if(is_winner(game_board) == 2){// checking if the player wins after his move.
            cout << "second player wins!" ;
            break ;
        }
        else if(is_winner(game_board) == 3){
            cout << "it's a draw" ;
            break;
        }
    }
    return 0;
}
