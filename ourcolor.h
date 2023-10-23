#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

struct color_t{
    int R, G, B;

    color_t(int r=0, int g=0, int b=0){
        R = r;
        G = g;
        B = b;
    }
};

#endif // COLOR_H_INCLUDED
