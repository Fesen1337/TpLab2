#define LOWLIMIT 0  //limits for the main menu
#define UPLIMIT 7

#define SHOW 1
#define ADD 2
#define REMOVE 3
#define EDIT 4
#define ALPHABETIC_SORT 5
#define SHOW_SHOP_PRODUCTS 6
#define EXIT 0

#include <iostream>
#include <string>
#include "InputCheck.h"
#include "Keeper.h"

using namespace std;

void printMenu();

int main() {
    Keeper keeper;

    ///////////////Testing//////////////////////
    keeper.add(new Order("qweda", 10.99, "sdsaa"), 0);
    keeper.add(new Order("qwdsaac", 200.33, "gercdsc"), 1);
    keeper.add(new Order("sdawqdqw", 20.11, "vtyngfb"), 2);
    keeper.add(new Order("aslknjn", 3, "ddvdvj"), 3);
    keeper.add(new Order("nfdvfdv", 20.11, "efew"), 4);


    //keeper.test();
    //cout << keeper.getOrder()[0]->getIn()[0] << endl;
    ///////////////Testing//////////////////////






    int position;
    while (true) {
        printMenu();
        switch (getIntValue(LOWLIMIT, UPLIMIT)) {
            cout << endl;
        case SHOW:
            keeper.showAllInfo();
            break;
        case ADD:
            cout << "Enter a position you want to add a order to (min is 1, max is "
                << keeper.getSize() + 1 << "):";
            position = getIntValue(1, keeper.getSize() + 1) - 1;
            cout << endl;
            keeper.add(new Order, position);    //adding a new order
            //keeper << new Order;
            break;
        case REMOVE:
            if (keeper.isEmpty()) {
                cout << endl << "The array is empty. Nothing to remove..." << endl << endl;
                break;
            }
            else {
                cout << "Here are all orders:" << endl;
                keeper.showAllInfo();
                cout << "What order you want to remove? Enter a number:";
                keeper >> keeper.getOrder()[getIntValue(1, keeper.getSize())-1];
                break;
            }
        case EDIT:
            cout << "Here are all orders:" << endl;
            keeper.showAllInfo();
            cout << "What order you want to edit? Enter a number:";
            keeper.getOrder()[getIntValue(1, keeper.getSize())-1]->edit();
            break;
        case ALPHABETIC_SORT:
            if (keeper.isEmpty()) {
                cout << endl << "The array is empty. Nothing to sort..." << endl << endl;
                break;
            }
            else {
                keeper.alphabeticSort();
                cout << endl << "The array has been alphabetically sorted." << endl << endl;
            }
            break;
        case SHOW_SHOP_PRODUCTS:
            cout << endl << "Please enter a out num of order: ";
            keeper.showOrdersNumOut(getStringValue());
            break;
        case EXIT:
            /*while (true) {
                cout << endl << "Confirm exiting. y/n:";
                _getch()
            }*/
            cout << endl << "Exiting the program." << endl << endl;
            return 0;
        default:
            cout << endl << "Wrong number entered." << endl;
            break;
        }
    }
	return 0;
}

void printMenu() {
    cout << "What do you want to do:" << endl;
    cout << "1. Show every order" << endl <<
        "2. Add a order" << endl <<
        "3. Remove a order" << endl <<
        "4. Edit a order" << endl <<
        "5. Sort the array alphabetically by the names of out " << endl <<
        "6. Show order with out order num" << endl <<
        "0. Exit the program" << endl << endl <<
        "Enter a number:";
}