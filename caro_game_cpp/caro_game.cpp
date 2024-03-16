#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <unistd.h> // sleep function
#include <io.h>
#include <fcntl.h>
#include <MMSystem.h>

#include "config.h"
#include "botbaseline.h"
#include "banco.h"
#include "carofont.h"

using namespace std;

int board_game[HEIGHT][WIDTH];
Point win_path[5];

void init_board_game();
void go_to_xy(Point p);
void set_text_color(int color);
void draw_tile(Point p, int color);
int who_win();
void draw_win_path(int winner);
void play_game(string* nameP1,string* nameP2);
Point player1_run();
Point player2_run();

void draw_background();


int main(){
    srand (time(NULL));

    SetConsoleTitle("Caro Game");
    string nameP1,nameP2;
    char luachon;
    set_text_color(WHITE_COLOR);
    char c;
    do{
        cout<<"Are you ready?(y/n)"<<endl;
        cin>>c;
    }while(c != 'y');
    system("cls");
    loading();
    bool Sound=PlaySound(TEXT("sound.wav"),NULL,SND_ASYNC);
    while(true){
         system("cls");
         text();
         cout<<"\n\n\t\t ========= MENU GAME ==========";
         cout<<"\n\n\t\t\t1. Play game";
         cout<<"\n\t\t\t2. Thanh vien nhom";
         cout<<"\n\t\t\t3. Huong dan choi";
         cout<<"\n\t\t\t4. Ket thuc";
         cout<<"\n\n\t\t ============ END =============";

         cout<<"\n Nhap lua chon";
         cin>>luachon;

         if(luachon=='1'){
            system("cls");
            dang_nhap(&nameP1,&nameP2);
            system("cls");
            PlaySound(NULL,0,0);
            play_game(&nameP1,&nameP2);
            PlaySound(TEXT("sound.wav"),NULL,SND_ASYNC);
        }
        else if(luachon=='2'){
            system("cls");
            set_text_color(13);
            cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
            cout<<"\n\t\t\t1. Nguyen Ngoc Quang    - 21021628 - Leader";
            cout<<"\n\t\t\t2. Pham Quoc Thai       - 21021634";
            cout<<"\n\t\t\t3. Nguyen Vu Thanh Long - 21021608";
            cout<<"\n\t\t\t4. Tran Ngoc Anh        - 21021560\n\n";
            //system("pause");
            char chr = ' ';
            cout<<endl<<endl<<"\n\t\t\tNhan phim bat ki de thoat\n\n";
	        chr = _getch();
            system("cls");
        }
        else if(luachon=='3'){
            system("cls");
            cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
            cout<<"\n - Ban co gom 50*30 o vuong";
            cout<<"\n - Di chuyen bang cac phim W,A,S,D";
            cout<<"\n - Danh X hoac O tai vi tri cham den bang phim K";
            cout<<"\n - Luat choi: Khi nguoi choi co 5 o X hoac O theo hang ngang, doc, cheo se chien thang\n";
            cout<<"\n ! Luu y: Khi tro choi ket thuc, hay cho 5s cho lan hanh dong tiep theo\n\n";
            //system("pause");
            char chr = ' ';
            cout<<endl<<endl<<"\n\t\t\tNhan phim bat ki de thoat\n\n";
	        chr = _getch();
            system("cls");
        }
        else if(luachon=='4'){
            break;}
         else {
            cout<<"\nLua chon khong hop le. Vui long nhap lai\n";
            system("pause");
         }

    }
    system("pause");
    return 0;
}

void init_board_game(){
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            board_game[i][j] = 0;
            //draw_tile(Point(BLOCK_RATIO*j, i), BLACK_COLOR);
        }
    }
}

void set_text_color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void go_to_xy(Point p){
    COORD coord;
    coord.X = p.x;
    coord.Y = p.y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void draw_win_path(int winner){

    bool turn = true;
    int color;
    int blink_count = 10;
    while(blink_count >= 0){
        if(winner == 1){
            if(turn) color = WHITE_COLOR;
            else color = BLACK_COLOR;
        } else {
            if(turn) color = RED_COLOR;
            else color = BLACK_COLOR;
        }
        for(int i = 0; i < 5; i++){
            draw_tile(win_path[i], color);
        }
        Sleep(500);
        turn = !turn;
        blink_count--;
    }

}

void draw_tile(Point p, int color){
    go_to_xy(p);
    set_text_color(color);
    for(int i = 0; i < BLOCK_RATIO; i++) {
        if(color == WHITE_COLOR)
            cout<<"O";
        else cout<<"X";
    }
}

// 1. player 1 win . 0 means hoa, -1. player 2 win
int who_win(){
    // YOUR CODE HERE
    for (int i=0 ; i<HEIGHT ;  i++){
        for (int j=0 ; j<WIDTH ; j++){
            if(board_game[i][j]!=0){
                //ngang
                if ((board_game[i][j]==board_game[i][j+1]) && (board_game[i][j+2]==board_game[i][j+1]) && (board_game[i][j+3]==board_game[i][j+1]) && (board_game[i][j]==board_game[i][j+4])){ //4 o bang nhau
                     return board_game[i][j];
                }

                //doc
                if ((board_game[i][j]==board_game[i+1][j]) && (board_game[i][j]==board_game[i+2][j]) && (board_game[i+3][j]==board_game[i][j]) && (board_game[i][j]==board_game[i+4][j]) ){ //4 o bang nhau
                     return board_game[i][j];
                }

                //cheo chinh
                if ((board_game[i][j]==board_game[i+1][j+1]) && (board_game[i][j]==board_game[i+2][j+2]) && (board_game[i+3][j+3]==board_game[i][j]) && (board_game[i+4][j+4]==board_game[i][j]) ){ //4 o bang nhau
                     return board_game[i][j];
                }

                //cheo phu
                 if ((board_game[i][j]==board_game[i+1][j-1]) && (board_game[i][j]==board_game[i+2][j-2]) && (board_game[i+3][j-3]==board_game[i][j]) && (board_game[i+4][j-4]==board_game[i][j]) ){ //4 o bang nhau
                     return board_game[i][j];
                }
            }
        }
    }
    return 0;
}

//goc toa do (0;0) o goc tren ben trai
void draw_background(){
    set_text_color(BLUE_COLOR);

    //Ve khung cho ban co
    for(int i=0; i <= WIDTH; i++){
        go_to_xy(Point(10+i, 3));
        cout << char(220);
        go_to_xy(Point(10+i, HEIGHT));
        cout << char(220);
    }

    for(int i=4 ;i<= HEIGHT;i++){
        go_to_xy(Point(10, i));
        cout << char(219);
        go_to_xy(Point(10+WIDTH,i));
        cout << char(219);
    }

    // Ve cac o trong ban co
    Point p;
    int x, y;
    for(int i = 11; i <= WIDTH; i += 2){
        for(int j = 4; j <= HEIGHT; j++){
            x = (i-1)/2;
            y = j;
            p.x = i;
            p.y = j;
            if(x % 2==0){
                if(y % 2==0){
                    draw_tile(p, BLACK_COLOR);
                }else{
                    draw_tile(p, WHITE_COLOR);
                }
            }
            else{
                if(y % 2==0){
                    draw_tile(p, WHITE_COLOR);
                }
                else{
                    draw_tile(p, BLACK_COLOR);
                }
            }
        }
    }
    set_text_color(WHITE_COLOR);
}

Point player1_run(Point p){
    //return player_rand(board_game, 1);
    //return player_baseline(board_game, 1);
    return player_move(board_game, 1,p);
}

Point player2_run(Point p){
    //return player_rand(board_game, -1);
    //return player_baseline(board_game, -1);
    return player_move(board_game, -1,p);
}

void play_game(string* nameP1,string* nameP2){
    bool turn_player1 = true;

    int turn_limit = 3000;
    int row, col, winner, repeat_pos;
    Point position,lastPoint;
    char c;
    //printBoard();

    do{
        printBoard();
        go_toxy(Point2(WIDTH+10+8+4,25)); cout<<(*nameP1)<<" TURN";
        init_board_game();

        turn_player1 = true;
        turn_limit = 3000;

        while(turn_limit > 0){
            repeat_pos = 5;
            if(turn_player1){
                do{
                    position = player1_run(lastPoint);
                    //go_toxy(Point2(WIDTH+10+8+4,25)); cout<<(*nameP2)<<" TURN";
                    if(repeat_pos == 0){
                        cout<<(*nameP1)<<" is so stupid"<<endl;
                        goto reset_game;
                    }
                    repeat_pos--;
                }while(board_game[position.x][position.y] != 0);
                lastPoint=position;
                board_game[position.x][position.y] = 1;
                draw_tile(Point(BLOCK_RATIO*position.y, position.x), WHITE_COLOR);
                bool Sound=PlaySound(TEXT("tap.wav"),NULL,SND_ASYNC);
            } else {
                do{
                    position = player2_run(lastPoint);
                    //go_toxy(Point2(WIDTH+10+8+4,25)); cout<<(*nameP1)<<" TURN";
                    if(repeat_pos == 0){
                        cout<<(*nameP2)<<" is so stupid"<<endl;
                        goto reset_game;
                    }
                    repeat_pos--;
                }while(board_game[position.x][position.y] != 0);
                lastPoint=position;
                board_game[position.x][position.y] = -1;
                draw_tile(Point(BLOCK_RATIO*position.y, position.x), RED_COLOR);
                bool Sound=PlaySound(TEXT("tap.wav"),NULL,SND_ASYNC);
            }
            if(turn_player1==true){

                for(int i=0;i<11;i++){
                    go_toxy(Point2(WIDTH+10+8+4+i,25));
                cout<<" ";}
                go_toxy(Point2(WIDTH+10+8+4,25));
                cout<<(*nameP2)<<" TURN";
            }
            if(turn_player1==false){
                for(int i=0;i<11;i++){
                    go_toxy(Point2(WIDTH+10+8+4+i,25));
                cout<<" ";}
                go_toxy(Point2(WIDTH+10+8+4,25));
                cout<<(*nameP1)<<" TURN";
            }
            winner = who_win();
            if(winner != 0){
                go_to_xy(Point((WIDTH/2)+10, HEIGHT-10));

                if(winner==1) cout<<(*nameP1)<<" WIN"<<endl;
                else cout<<(*nameP2)<<" WIN"<<endl;
                bool Sound=PlaySound(TEXT("wingame.wav"),NULL,SND_ASYNC);
                draw_win_path(winner);
                break;
            }

            turn_player1 = !turn_player1;

            turn_limit--;
            Sleep(PAUSE_TIME);
        }
        reset_game:
        set_text_color(WHITE_COLOR);
        system("pause");
        go_to_xy(Point(WIDTH/3, HEIGHT-20));
        system("cls");
        cout<<"\n\t\t===== Ban co muon choi lai khong? ======";
        cout<<"\n\t CO = y";
        cout<<"\n\t KHONG = n";
        cout<<"\n\t Nhap: ";
        cin>>c;
        if(c=='y') system("cls");
    }while(c == 'y');


}
