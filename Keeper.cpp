#define MAXLIMIT 30
#include "Keeper.h"


void Keeper::add(Order* orderPtr, int position)
{
	Order** tmp = Keeper::order;
	Keeper::size++;
	order = new Order * [Keeper::size];
	order[position] = orderPtr;	//adding new order to the end of the array
	for (int i = 0,j=0; i < size; i++) {
		if (i != position) {
			order[i] = tmp[j];
			j++;
		}
		else
			continue;
	}
}

void Keeper::remove(Order* orderPtr)
{
	Order** tmp = Keeper::order;
	Keeper::size--;
	order = new Order * [Keeper::size];
	for (int i = 0; i <= size; i++) {	//"i <= size" because i have to check all elements of the initial array
		if (tmp[i] != orderPtr) {
			order[i] = tmp[i];
		}
		else {
			i++;
			for (int j = i - 1; i <= size; j++, i++)
				order[j] = tmp[i];
			break;
		}
	}
	delete orderPtr;
	cout << endl << "The element has been removed" << endl << endl;
}

void Keeper::showAllInfo() {
	if (size == 0)		//array is empty
		cout << endl << "The array is empty. Nothing to show for now..." << endl << endl;
	else
		for (int i = 0; i < size; i++) {
			cout << endl << "~~~~~~~~~~~~~~~~~~" << endl;
			cout << i + 1 << "." << endl;
			getOrder()[i]->showInfo();
			cout << "~~~~~~~~~~~~~~~~~~" << endl << endl;
		}
}

bool Keeper::isEmpty()
{
	if (Keeper::size > 0)
		return false;
	else
		return true;
}


Order& Keeper::operator<<(Order* orderPtr)
{
	cout << "Enter a position you want to add a order to (min is 1, max is "
		<< Keeper::getSize() + 1 << "):";
	int position = getIntValue(1, Keeper::getSize() + 1) - 1;
	Order** tmp = Keeper::order;
	Keeper::size++;
	order = new Order * [Keeper::size];
	order[position] = orderPtr;	//adding new order to the end of the array
	for (int i = 0, j = 0; i < size; i++) {
		if (i != position) {
			order[i] = tmp[j];
			j++;
		}
		else
			continue;
	}
	return **order;
}

Order& Keeper::operator>>(Order* orderPtr)
{
	Order** tmp = Keeper::order;
	Keeper::size--;
	order = new Order * [Keeper::size];
	for (int i = 0; i <= size; i++) {	//"i <= size" because i have to check all elements of the initial array
		if (tmp[i] != orderPtr) {
			order[i] = tmp[i];
		}
		else {
			i++;
			for (int j = i - 1; i <= size; j++, i++)
				order[j] = tmp[i];
			break;
		}
	}
	delete orderPtr;
	cout << endl << "The element has been removed" << endl << endl;
	return **order;
}

void Keeper::alphabeticSort(){	
	for (int i = 0; i < Keeper::getSize(); i++){
		for (int j = 0; j < Keeper::getSize() - i - 1; j++) {
			char firstCharLine1 = getOrder()[j]->getOut()[0];	//first character of the string
			int k = 0;
			while (true) {
				if (firstCharLine1 == ' ' || firstCharLine1 == '.' || firstCharLine1 == ',' || firstCharLine1 == '-') {
					firstCharLine1 = getOrder()[j]->getOut()[k];
					k++;
				}
				else
					break;
			}
			char firstCharLine2 = getOrder()[j+1]->getOut()[0];	//first character of the string
			k = 0;
			while (true) {
				if (firstCharLine2 == ' ') {
					firstCharLine2 = getOrder()[j + 1]->getOut()[k];
					k++;
				}
				else
					break;
			}
			if (firstCharLine1 == firstCharLine2) {
				int q = 0;
				for (; order[j]->getOut()[q] == order[j + 1]->getOut()[q]; q++) {
					firstCharLine1 = order[j]->getOut()[q];
					firstCharLine2 = order[j + 1]->getOut()[q];
				}
				firstCharLine1 = order[j]->getOut()[q];
				firstCharLine2 = order[j + 1]->getOut()[q];
			}

			if (firstCharLine1 > firstCharLine2) {
				Order* tmp = *(getOrder()+j);
				*(getOrder()+j) = *(getOrder() + j + 1);
				*(getOrder()+j + 1) = tmp;
			}
		}
	}
}

void Keeper::showOrdersNumOut(string out)
{
	bool flag = false;	//flag is 1 if a match has been found; otherwise - it's 0
	if (isEmpty())
		cout << endl << "The array is empty. Nothing to show for now..." << endl << endl;
	else
		for (int i = 0; i < Keeper::getSize(); i++) {
			if (order[i]->getOut() == out) {
				flag = true;
				cout << endl << "~~~~~~~~~~~~~~~~~~" << endl;
				cout << i + 1 << "." << endl;
				order[i]->showInfo();
				cout << "~~~~~~~~~~~~~~~~~~" << endl << endl;
			}
		}
	if (!flag)
		cout << endl << "Entered order not found." << endl << endl;
}



void Keeper::setOrder(Order* order)
{
	this->order = &order;
}


Order** Keeper::getOrder()
{
	return order;
}

int Keeper::getSize()
{
	return Keeper::size;
}

Keeper::Keeper() {
	cout << "Keeper's constructor " << this << " is called" << endl;
	size = 0;
	order = new Order * [size];
}

Keeper::~Keeper()
{
	cout << "Keeper's destructor " << this << " is called" << endl;
	for (int i = 0; i < size; i++) {

		delete order[i];
	}
	order = nullptr;
	size = 0;
}
