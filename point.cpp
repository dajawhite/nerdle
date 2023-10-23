#include "point.h"
#include "ourconstants.h"

point::point(int x, int y){
    setX(x);
    setY(y);
}

void point::setX(int x){
    if(x >= 0 && x < NUM_COL){
        this->x = x;
    }
}

void point::setY(int y){
    if(y >= 0 && y < NUM_ROWS){
        this->y = y;
    }
}

int point::getX()const{
    return x;
}

int point::getY()const{
    return y;
}
