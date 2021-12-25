#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <climits>
#include <cfloat>

using namespace std;

int getIntValue(int lowLimit, int upLimit);

int getIntValue(int lowLimit, int upLimit, int mySeconds);	//time-depended data enter


string getStringValue();

bool isInvalidInput(string line);

double getDoubleValue(double lowLimit, double upLimit);
