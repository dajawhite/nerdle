#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

#include "ourcolor.h"

const int NUM_ROWS = 800;
const int NUM_COL = 800;

const int START_T = 80; //starting location for top of tile.
const int START_L = 80; //starting location for left side of tile.
const int T_SPACE = 80; //space between tiles.

const int MAX_SIZE = 8; //Tiles per horizontal.
const int MAX_TRIES = 6; //Tiles per vertical.

const int TILE_S = 70; //tile size, height and width (squares).

const int SIZEOFNUM = 3;

const color_t BLACK(22, 24, 3);
const color_t GRAY (152, 148, 132);
const color_t GREEN(57, 136, 116);
const color_t PURPLE(130, 4, 88);
const color_t DARK_GRAY(75, 75, 75);


const int FONT_ROW = 105;
const int FONT_COL = 90;

const double SIZE = 0.4;

#endif // CONSTANTS_H_INCLUDED
