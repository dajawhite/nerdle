#ifndef GAMEOBJECT_H_INCLUDED
#define GAMEOBJECT_H_INCLUDED
#include <vector>
#include <fstream>
#include "ourconstants.h"
#include "point.h"
#include "ourtile.h"
#include "nerdle1.h"
#include "random.h"

using namespace std;

struct GameObject{
    int x, y;
    point location;
    tile tile1;
    vector<point> pointUpdate;
    vector<tile> tileUpdate;
    string fileName[16] = {"zeroData.txt", "oneData.txt", "twoData.txt",
                            "threeData.txt", "fourData.txt", "fiveData.txt",
                            "sixData.txt", "sevenData.txt", "eightData.txt",
                            "nineData.txt", "plusData.txt", "minusData.txt",
                            "multiplyData.txt", "divideData.txt", "equalData.txt",
                            "spaceData.txt"};
    vector<char[FONT_ROW][FONT_COL]> font{16};
    bool over = false;

    GameObject();
    point slideRight();
    void slideLeft();
    void drop();
    void setColor(int);
    void resetX();

    void cleartileUpdate();
    void clearpointUpdate();

    void printLetter(point, SDL_Plotter&, char);

    int assignKeytoInt(char);

    void draw(SDL_Plotter& g, tile& t);

    void caseCode(string&, char, int&, SDL_Plotter&);

    void switchCode(char, int&, string&, SDL_Plotter&, int&, string);

    vector<int> tileCheck(string const, string const, SDL_Plotter&);

    void processKey(SDL_Plotter&, char&, int&, string&, int&, string&);




};


#endif // GAMEOBJECT_H_INCLUDED
