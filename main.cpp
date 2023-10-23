#include <iostream>
#include "SDL_Plotter.h"
#include "ourcolor.h"
#include "point.h"
#include "ourtile.h"
#include "ourconstants.h"
#include "GameObject.h"
#include "MainFunctions.h"
#include "nerdle1.h"
#include "random.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;


int main(int argc, char **argv){

    //DATA ABSTRACTION
    SDL_Plotter g(NUM_ROWS, NUM_COL);

    string userData;
    char key;
    GameObject gg;
    int keyCount = 0;
    string input = "";
    int rowCount = 0;
    tile t;
    point p;
    bool keepGoing = true;

    //MAKE MATRIX
    getLocations(g, t, p);
    createTileMatrix(g, t, p);

    //GENERATE SOLUTION

    string sol;
    sol = generateSol();
    /*
    for (int i = 0; i < 8; ++i){
        cout << sol.at(i);
    }
    cout << endl;
    */

    //RUN GAME

    while(!g.getQuit()){
        if(g.kbhit()){
            if(rowCount < MAX_TRIES || !gg.over){
                key = g.getKey();

                gg.processKey(g, key, keyCount, input, rowCount, sol);

            }
            if(gg.over){
                cout << "Game OVER" << endl;
            }

        }
        g.update();
    }

    return 0;
}
