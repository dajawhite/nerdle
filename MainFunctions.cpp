#include "MainFunctions.h"

//BOOT UP GAME: CREATE TILE MATRIX -- assign the tile a location, size, and color
void createTileMatrix(SDL_Plotter& g, tile& t, point& p){
    tile tArray[MAX_TRIES][MAX_SIZE];
    vector<point> locations = getLocations(g, t, p);
    int i = 0;
    for (unsigned int r = 0; r < MAX_TRIES; r++){
        for (unsigned int c = 0; c < MAX_SIZE; c++){
            tArray[r][c].setLocation(locations.at(i));
            tArray[r][c].setHeight(TILE_S);
            tArray[r][c].setWidth(TILE_S);
            tArray[r][c].setColor(GRAY);
            i++;

        }
    }

    for (int r = 0; r < MAX_TRIES; r++){
        for (int c = 0; c < MAX_SIZE; c++){
            tArray[r][c].grid(g); //print grid with tile objects
            g.update();
        }
    }
}

//VECTOR LOCATIONS
vector<point> getLocations(SDL_Plotter& g, tile t, point& p){
    vector<point> list;

    for(int y = START_T; y < START_T + (MAX_TRIES * T_SPACE); y += T_SPACE){
        for(int x = START_L; x < START_L + (MAX_SIZE * T_SPACE); x += T_SPACE){
            p.setX(x);
            p.setY(y);

            t.setLocation(p);

            list.push_back(t.getLocation());

        }
    }

    return list;
}
