#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#include <vector>
#include <fstream>
#include "point.h"
#include "ourcolor.h"
#include "ourconstants.h"
#include "SDL_Plotter.h"

using namespace std;

class tile{
    private:
        point location;
        color_t color;
        int width, height;
        char letter;

    public:
        tile();
        void setLocation(const point&);
        void setColor(const color_t&);
        void setHeight(int);
        void setWidth(int);
        void setLetter(char);

        point getLocation() const;
        color_t getColor() const;
        int getHeight() const;
        int getWidth() const;
        char getLetter() const;

        void grid(SDL_Plotter&) const;
};

#endif // TILE_H_INCLUDED
