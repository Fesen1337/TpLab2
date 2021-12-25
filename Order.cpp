#include "Order.h"

string Order::getIn()
{
	return this->in;
}

string Order::getOut()
{
	return this->out;
}

void Order::showInfo()
{
	cout << "In num of the order is: " << Order::in << endl;
	cout << "Cost of the order is: " <<Order::price << endl;
	cout << "Out num if the order is: " << Order::out << endl;
}

void Order::edit()
{
	cout << "Name of the order is: " << Order::in << endl;
	cout << "Enter a new in num of the order: ";
	this->in = getStringValue();
	cout << "Cost of the order is: " << Order::price << endl;
	cout << "Enter a new cost of the order: ";
	this->price = getDoubleValue(0,DBL_MAX);	
	cout << "Out num of the order is: " << Order::out << endl;
	cout << "Enter a new out num of the order: ";
	this->out = getStringValue();
}

Order::Order()
{
	cout << "Order's constructor " << this << " is called" << endl;
	cout << endl << "Please enter a in num of the order: ";
	Order::in = getStringValue();
	cout << endl << "Please enter a cost of the order: ";
	Order::price = getDoubleValue(0, DBL_MAX);
	cout << endl << "Please enter a out num of the order: ";
	Order::out = getStringValue();
}

Order::Order(string in, double price, string out)
{
	cout << "Order's constructor with parameters " << this << " is called" << endl;
	this->in = in;
	this->out = out;
	this->price = price;
}

Order::~Order()
{
	cout << "Order's destructor " << this << " is called" << endl;

}
