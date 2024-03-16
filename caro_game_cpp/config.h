#ifndef CONFIG
#define CONFIG

struct Point{
    int x, y;
    Point(){
        x = 0;
        y = 0;
    }

    Point(int x_, int y_){
        x = x_;
        y = y_;
    }

    void operator=(Point p){
        x = p.x;
        y = p.y;
    }
};

struct Point2{
    double x, y;
    Point2(){
        x = 0;
        y = 0;
    }

    Point2(double x_, double y_){
        x = x_;
        y = y_;
    }

    void operator=(Point2 p){
        x = p.x;
        y = p.y;
    }
};

const int BLUE_COLOR = 1;
const int BLACK_COLOR = 0;
const int RED_COLOR = 4;
const int PURPLE_COLOR = 5;
const int WHITE_COLOR = 7;
const int WIDTH = 50;
const int HEIGHT = 30;
const int PAUSE_TIME = 100; // milisecond
const int BLOCK_RATIO = 1;

#endif // CONFIG
