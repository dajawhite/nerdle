#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include "SDL_Plotter.h"

class point{
    private:
        int x, y;
    public:
        point(int = 0, int = 0);
        void setX(int = 0);
        void setY(int = 0);

        int getX() const;
        int getY() const;

};

#endif // POINT_H_INCLUDED
