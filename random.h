#ifndef RANDOM_H_INCLUDED
#define RANDOM_H_INCLUDED

#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;

//generates the random solution
string generateSol();

//used to find the answer to random equation
int findSolAnswer(string);

//used to validate the equation
bool evaluate(string);

#endif // RANDOM_H_INCLUDED
