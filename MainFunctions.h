#ifndef MAINFUNCTIONS_H_INCLUDED
#define MAINFUNCTIONS_H_INCLUDED

#include <vector>
#include "SDL_Plotter.h"
#include "ourtile.h"
#include "ourconstants.h"
#include "ourcolor.h"
using namespace std;


void createTileMatrix(SDL_Plotter& g, tile& t, point& p);
vector<point> getLocations(SDL_Plotter& g, tile t, point& p);

#endif // MAINFUNCTIONS_H_INCLUDED
