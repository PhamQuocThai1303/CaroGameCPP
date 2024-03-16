#ifndef BANCO
#define BANCO
#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;
void go_toxy(Point2 p);
void printBoard(){
    //khung trên
     for(int i=0; i <= WIDTH; i++){
        go_toxy(Point2(10+i, 3));
        cout << char(220);

    }

     //khung 2 bên
     for(int i=4 ;i<= HEIGHT;i++){
        go_toxy(Point2(10, i));
        cout << char(219);

        go_toxy(Point2(10+WIDTH,i));
        cout << char(219);
     }
     //khung dưới
     for(int i=0; i < WIDTH; i++){
        go_toxy(Point2(10+i, HEIGHT));
        cout << char(220);
    }
     //khung giữa
    int x, y;
    for(double i = 11; i < WIDTH+10; i ++){
        for(double j = 4; j < HEIGHT; j++){
        double x=(i*2 +1)/2;
        double y=(j*2 +1)/2;
        go_toxy(Point2(x,y));
            cout << char(250);
        }
    }
    //khung nguoi choi
    for(int i=WIDTH+10+1;i<= WIDTH+10+8;i++){
        go_toxy(Point2(i, 10));
        cout<<char(205);
    }
    for(int i=WIDTH+10+8; i <= WIDTH+10+8+12+7; i++){
        go_toxy(Point2(i, 8));
        cout << char(220);
    }
    for(int i=WIDTH+10+8; i <= WIDTH+10+8+12+7; i++){
        go_toxy(Point2(i, 13));
        cout << char(220);
    }
    for(int j=9 ;j<= 13;j++){
        go_toxy(Point2(WIDTH+10+8,j));
        cout << char(219);

        go_toxy(Point2(WIDTH+10+8+12+7,j));
        cout << char(219);
     }
     go_toxy(Point2(WIDTH+10+8+2,10)); cout<<"Nguoi choi 1 : O";
     go_toxy(Point2(WIDTH+10+8+2,12)); cout<<"Nguoi choi 2 : X";

     //khung luot choi
     for(int i=WIDTH+10+1;i<= WIDTH+10+8;i++){
        go_toxy(Point2(i, 25));
        cout<<char(205);
    }
    for(int i=WIDTH+10+8; i <= WIDTH+10+8+12+7; i++){
        go_toxy(Point2(i, 23));
        cout << char(220);
    }
    for(int i=WIDTH+10+8; i <= WIDTH+10+8+12+7; i++){
        go_toxy(Point2(i, 27));
        cout << char(220);
    }
    for(int j=24 ;j<= 27;j++){
        go_toxy(Point2(WIDTH+10+8,j));
        cout << char(219);

        go_toxy(Point2(WIDTH+10+8+12+7,j));
        cout << char(219);
     }
     go_toxy(Point2(WIDTH+10+8+4,22)); cout<<"Luot choi:";
}
void go_toxy(Point2 p){
    COORD coord;
    coord.X = p.x;
    coord.Y = p.y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void loading(){
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t Loading :";
    for(int i=0;i<35;i++){
        cout<<char(219);
        if(i<10) Sleep(250);
        if(i>=10 && i<20) Sleep(150);
        if(i>=20&&i<30) Sleep(100);
        else Sleep(300);
    }
    system("cls");
}
void dang_nhap(string* nameP1,string* nameP2){

     do{
        system("cls");
        go_toxy(Point2(20,5));
        cout<<"! Ten nguoi choi phai it hon 6 ki tu";
        go_toxy(Point2(20,10));
        cout<<"Nhap ten nguoi choi 1: ";
        cin>>(*nameP1);
    }while((*nameP1).length() >= 6);
    do{
        system("cls");
        go_toxy(Point2(20,5));
        cout<<"Ten nguoi choi phai it hon 6 ki tu";
        go_toxy(Point2(20,12));
        cout<<"Nhap ten nguoi choi 2: ";
        cin>>(*nameP2);
    }while((*nameP2).length() >= 6 || (*nameP2)==(*nameP1));
}
#endif // BANCO
