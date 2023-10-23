#ifndef NERDLE1_H_INCLUDED
#define NERDLE1_H_INCLUDED

#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>

using namespace std;

bool doesEvaluate(string);

bool isValid(string);

bool isCorrect(string, string);

void displayEquation(vector<char>&);

#endif // NERDLE1_H_INCLUDED
