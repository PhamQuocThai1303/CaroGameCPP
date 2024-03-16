#ifndef CAROFONT
#define CAROFONT
#include<iostream>
#include<windows.h>
using namespace std;

void set_textcolor(int color);
void set_textcolor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void text(){
     set_textcolor(rand()%15 +1);
     cout<<" .----------------.  .----------------.  .----------------.  .----------------."<<endl;
     cout<<"| .--------------. || .--------------. || .--------------. || .--------------. |"<<endl;
     cout<<"| |     ______   | || |      ____    | || |  _______     | || |     ____     | |"<<endl;
     cout<<"| |   .' ___  |  | || |     /    |   | || | |_   __ |    | || |   .'    `.   | |"<<endl;
     cout<<"| |  | .'   |_|  | || |    / /// |   | || |   | |__) |   | || |  |  .--.  |  | |"<<endl;
     cout<<"| |  | |         | || |   / ___  |   | || |   |  __ /    | || |  | |    | |  | |"<<endl;
     cout<<"| |  | `.___.'|  | || | _/ /  _| |_  | || |  _| |  | |_  | || |  |  `--'  |  | |"<<endl;
     cout<<"| |   `._____.'  | || ||____||_____| | || | |____| |___| | || |   `.____.'   | |"<<endl;
     cout<<"| |              | || |              | || |              | || |              | |"<<endl;
     cout<<"| '--------------' || '--------------' || '--------------' || '--------------' |"<<endl;
     cout<<" '----------------'  '----------------'  '----------------'  '----------------' ";
     set_textcolor(7);

}

#endif // CAROFONT
