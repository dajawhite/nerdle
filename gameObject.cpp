#include "gameObject.h"
#include "ourconstants.h"

GameObject::GameObject(){
    ifstream inputFile;

    x = START_L;
    y = START_T;

    location.setX(x);
    location.setY(y);

    tile1.setHeight(TILE_S);
    tile1.setWidth(TILE_S);
    tile1.setColor(GRAY);
    tile1.setLocation(location);

    pointUpdate.push_back(location);
    tileUpdate.push_back(tile1);

    for(int i = 0; i <= 15; i++){
        inputFile.open(fileName[i]);

        for(int r = 0; r < FONT_ROW; r++){
            for(int c = 0; c < FONT_COL; c++){
                inputFile >> font.at(i)[r][c];
            }
        }

        inputFile.close();
    }
}


point GameObject::slideRight(){
    x = x + T_SPACE;

    location.setX(x);

    pointUpdate.push_back(location);

    tile1.setLocation(location);
    tileUpdate.push_back(tile1);

    return location;
}

void GameObject::slideLeft(){
    x = x - T_SPACE;
    pointUpdate.pop_back();

    tileUpdate.pop_back();
}

void GameObject::drop(){
    y = y + T_SPACE;

    location.setX(x);
    location.setY(y);

    pointUpdate.push_back(location);

    tile1.setLocation(location);
    tileUpdate.push_back(tile1);

}

void GameObject::cleartileUpdate(){
    tileUpdate.clear();
}

void GameObject::clearpointUpdate(){
    pointUpdate.clear();
}

void GameObject::setColor(int color){
    if(color == 2){
        tile1.setColor(GREEN);
    }
    else if(color == 1){
        tile1.setColor(PURPLE);
    }
    else{
        tile1.setColor(BLACK);
    }

}

void GameObject::resetX(){
    x = START_L;
}

int GameObject::assignKeytoInt(char key){
    int n;
    switch(key){
        case '0': n = 0;
            break;
        case '1': n = 1;
            break;
        case '2': n = 2;
            break;
        case '3': n = 3;
            break;
        case '4': n = 4;
            break;
        case '5': n = 5;
            break;
        case '6': n = 6;
            break;
        case '7': n = 7;
            break;
        case '8': n = 8;
            break;
        case '9': n = 9;
            break;
        case '+': n = 10;
            break;
        case '-': n = 11;
            break;
        case '*': n = 12;
            break;
        case '/': n = 13;
            break;
        case '=': n = 14;
            break;
        case ' ': n = 15;
            break;

    }
    return n;
}

void GameObject::printLetter(point l, SDL_Plotter& g, char key){
    int xVal, yVal;
    int keyInt = assignKeytoInt(key);

    for(int y = 0; y < FONT_ROW; y++){
        for(int x = 0; x < FONT_COL; x++){
            if(font.at(keyInt)[y][x] == '1'){
                for(int xFact = -SIZE; xFact <= SIZE; xFact++){ //in case of width, divide by int
                    for(int yFact = -SIZE; yFact <= SIZE; yFact++){
                        xVal = xFact + l.getX() + 18 + x * SIZE; //FIXME magic numbers
                        yVal = yFact + l.getY() + 14 + y * SIZE; //FIXME magic numbers
                        if(xVal >= 0 && xVal < g.getCol() && yVal >= 0 && yVal < g.getRow()){ //guard to prevent from crashing
                            g.plotPixel(xVal, yVal, 255, 255, 255); //column x coordinate, row y coordinate
                        }
                    }
                }
            }
        }
    }
}

void GameObject::draw(SDL_Plotter& g, tile& t){
    for(int x = 0; x < TILE_S; x++){
        for(int y = 0; y < TILE_S; y++){
            g.plotPixel(t.getLocation().getX() + x, t.getLocation().getY() + y, t.getColor().R, t.getColor().G, t.getColor().B);
        }
    }

    printLetter(t.getLocation(), g, t.getLetter());
}

void GameObject::caseCode(string& input, char key, int& keyCount,
                          SDL_Plotter& g){
    tileUpdate.at(keyCount).setColor(DARK_GRAY);
    draw(g, tileUpdate.at(keyCount));
    keyCount++;
    slideRight();

    if(input.size() < MAX_SIZE){
        input += key;
    }

}

void GameObject::switchCode(char key, int& keyCount, string& input,
                            SDL_Plotter& g, int& rowCount, string sol){
    int returnCount = 0;
    int correctCount = 0;
    vector<char> user;
    vector<int> holdColor;
        switch(key){
            case '0': if(keyCount < MAX_SIZE){
                        tileUpdate.at(keyCount).setLetter('0');
                        caseCode(input, key, keyCount, g);
                      }
                      break;
            case '1': if(keyCount < MAX_SIZE){
                        tileUpdate.at(keyCount).setLetter('1');
                        caseCode(input, key, keyCount, g);
                      }
                      break;
            case '2': if(keyCount < MAX_SIZE){
                        tileUpdate.at(keyCount).setLetter('2');
                        caseCode(input, key, keyCount, g);
                      }
                      break;
            case '3': if(keyCount < MAX_SIZE){
                        tileUpdate.at(keyCount).setLetter('3');
                        caseCode(input, key, keyCount, g);
                      }
                      break;
            case '4':if(keyCount < MAX_SIZE){
                        tileUpdate.at(keyCount).setLetter('4');
                        caseCode(input, key, keyCount, g);
                      }
                      break;
            case '5': if(keyCount < MAX_SIZE){
                        tileUpdate.at(keyCount).setLetter('5');
                        caseCode(input, key, keyCount, g);
                      }
                      break;
            case '6':if(keyCount < MAX_SIZE){
                        tileUpdate.at(keyCount).setLetter('6');
                        caseCode(input, key, keyCount, g);
                      }
                      break;
            case '7':if(keyCount < MAX_SIZE){
                        tileUpdate.at(keyCount).setLetter('7');
                        caseCode(input, key, keyCount, g);
                      }
                      break;
            case '8':if(keyCount < MAX_SIZE){
                        tileUpdate.at(keyCount).setLetter('8');
                        caseCode(input, key, keyCount, g);
                      }
                      break;
            case '9':if(keyCount < MAX_SIZE){
                        tileUpdate.at(keyCount).setLetter('9');
                        caseCode(input, key, keyCount, g);
                      }
                      break;
            case '+':if(keyCount < MAX_SIZE){
                        tileUpdate.at(keyCount).setLetter('+');
                        caseCode(input, key, keyCount, g);
                      }
                      break;
            case '-':if(keyCount < MAX_SIZE){
                        tileUpdate.at(keyCount).setLetter('-');
                        caseCode(input, key, keyCount, g);
                      }
                      break;
            case '*':if(keyCount < MAX_SIZE){
                        tileUpdate.at(keyCount).setLetter('*');
                        caseCode(input, key, keyCount, g);
                      }
                      break;
            case '/':if(keyCount < MAX_SIZE){
                        tileUpdate.at(keyCount).setLetter('/');
                        caseCode(input, key, keyCount, g);
                      }
                      break;
            case '=': if(keyCount < MAX_SIZE){
                        tileUpdate.at(keyCount).setLetter('=');
                        caseCode(input, key, keyCount, g);
                      }
                      break;
            case SDLK_DELETE: if(input.size() > 0 && keyCount != 0){
                                input = input.substr(0, input.size() - 1);
                                tileUpdate.at(keyCount - 1).setColor(GRAY);
                                tileUpdate.at(keyCount - 1).setLetter(' ');
                                draw(g, tileUpdate.at(keyCount -1));
                                slideLeft();
                                keyCount--;
                              }
                              break;
            case SDLK_RETURN: if(keyCount == MAX_SIZE){
                                  cout << input << endl;
                                  returnCount++;
                                  if(doesEvaluate(input) && isValid(input)){
                                    keyCount = 0;


                                    tileCheck(input, sol, g);

                                    for(unsigned int i; i < tileCheck(input,sol,g).size(); i++){
                                        if(tileCheck(input, sol, g).at(i) == 0){
                                            correctCount++;
                                            if(correctCount == 8){
                                                over = true;
                                            }
                                        }
                                    }
                                    rowCount++;

                                    clearpointUpdate();
                                    cleartileUpdate();
                                    returnCount = 0;

                                    resetX();
                                    drop();
                                    input.clear();
                                  }
                                  else if(returnCount == 1 && keyCount > 0){
                                    for(int j = 0; j < MAX_SIZE; j++){
                                        input = input.substr(0, input.size() - 1);
                                        tileUpdate.at(keyCount - 1).setColor(GRAY);
                                        tileUpdate.at(keyCount - 1).setLetter(' ');
                                        draw(g, tileUpdate.at(keyCount -1));
                                        slideLeft();
                                        keyCount--;
                                    }
                              }
            }

                              break;
        }

}

vector<int> GameObject::tileCheck(string user, string s, SDL_Plotter& g){
    char green = 219;
    char purple = 178;
    char black = 177;
    vector<int> holdColor;

    for (unsigned int i = 0; i < user.size(); ++i){
        if(user.at(i) == s.at(i)){
            cout << green << green;
            holdColor.push_back(0);//number is in correct spot
            tileUpdate.at(i).setColor(GREEN);
        }
        else if(find(s.begin(), s.end(), user.at(i)) != s.end()){
            cout << purple << purple;  //number is in answer but wrong spot
            holdColor.push_back(1);
            tileUpdate.at(i).setColor(PURPLE);
        }
        else{
            cout << black << black;  //number is not in answer
            holdColor.push_back(2);
            tileUpdate.at(i).setColor(BLACK);
        }

        draw(g, tileUpdate.at(i));

    cout << " ";
    }

    cout << endl;
    for (unsigned int i = 0; i < user.size(); ++i){
        cout << " " << user.at(i) << " ";
    }
    cout << endl << endl;

    return holdColor;
}

void GameObject::processKey(SDL_Plotter& g, char& key, int& keyCount,
                            string& input, int& rowCount, string& sol){
    if(over){
        cout << "Game OVER!!!" << endl;
    }
    else{
        switchCode(key, keyCount, input, g, rowCount, sol);
    }
}
