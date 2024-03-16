#ifndef BOTBASELINE
#define BOTBASELINE

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "config.h"
void goto_xy(int col,int row);
/*Point check_win(int board_game[][WIDTH], int player_id);
Point defend(int board_game[][WIDTH], int player_id);
Point attack(int board_game[][WIDTH], int player_id);
Point check_n_tile(int board_game[][WIDTH], int player_id, int n);*/

// player_id = 1 || -1
Point player_rand(int board_game[][WIDTH], int player_id){
    int row, col;
    row = rand() % HEIGHT;
    col = rand() % WIDTH;
    return Point(row, col);
}

Point player_move(int board_game[][WIDTH], int player_id,Point p){

    int col,row;
    if(p.x==0 && p.y==0){
        row=25;
        col=15;
    }
    else {
        row=p.y-9;
        col=p.x;
    }
    while(true){
        char dk;
        if(kbhit()){
           dk = getch();
           if(dk=='a') row-=1;
           if(dk=='w') col-=1;
           if(dk=='s') col+=1;
           if(dk=='d') row+=1;

           if(row<=0) row=49;
           else if(row>=50) row=1;
           if(col-3<=0) col=29;
           else if(col>=30) col=4;

           goto_xy(col,row+10);
           Sleep(20);
           if(dk=='k') return Point(col,row+10);
        }

    }
    //return Point(row, col);

}
/*Point player_baseline(int board_game[][WIDTH], int player_id){
    Point p = check_win(board_game, player_id);
    if(p.x != -1 && p.y != -1){
        return p;
    } else {
        p = defend(board_game, player_id);
        if(p.x != -1 && p.y != -1){
            return p;
        } else {
            return attack(board_game, player_id);
        }
    }
}*/
void goto_xy(int col,int row){
    COORD coord;
    coord.X = row;
    coord.Y = col;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
#endif // BOTBASELINE
