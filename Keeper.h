#pragma once
#include "Order.h"
#include <fstream>
#include <climits>
#include <cfloat>

class Keeper	
{
private:
	int size;	//size of the dynamic array of pointers
	Order** order;
	void setOrder(Order* order);
public:	
	void add(Order* orderPtr, int position);	
	void remove(Order* orderPtr);
	Order** getOrder();
	int getSize();
	void showAllInfo();
	bool isEmpty();

	void alphabeticSort();
	void showOrdersNumOut(string out);

	Order& operator<<(Order* orderPtr);
	Order& operator>>(Order* orderPtr);


	Keeper();
	~Keeper();
};

