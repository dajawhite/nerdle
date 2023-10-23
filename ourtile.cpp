#include "ourtile.h"

tile::tile(){
    width = 70;
    height = 70;
    letter = ' ';
}

void tile::setLocation(const point& p){
    location = p;
}

void tile::setColor(const color_t& c){
    color = c;
}

void tile::setHeight(int l){
    height = l;
}

void tile::setWidth(int w){
    width = w;
}

void tile::setLetter(char let){
    letter = let;
}

point tile::getLocation() const{
    return location;
}

color_t tile::getColor() const{
    return color;
}

int tile::getHeight() const{
    return height;
}

int tile::getWidth() const{
    return width;
}

char tile::getLetter() const{
    return letter;
}

void tile::grid(SDL_Plotter& g) const{
    for(int x = 0; x < width; x++){
        for(int y = 0; y < height; y++){
            g.plotPixel(location.getX() + x, location.getY() + y, color.R, color.G, color.B);
        }
    }
}
