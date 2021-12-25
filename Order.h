#pragma once
#include <iostream>
#include <string>
#include <climits>
#include <cfloat>
#include "InputCheck.h"

using namespace std;

class Order
{
private:
	string in;
	string out;
	double price;
public:
	string getIn();
	string getOut();
	void showInfo();
	void edit();

	Order();
	Order(string in, double price, string out);
	~Order();
};