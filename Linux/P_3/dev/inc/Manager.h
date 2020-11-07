#ifndef MANAGER_H
#define MANAGER_H
#include "../inc/common.h"
#include <string>
using namespace std;

class Manager {

	int password ;
	int cutline; int netprofit; int sale; int negativedebt;
	int sugar; int milk; int cacao; int coffeebeans; int water;
	string menu[4];
	bool available[4];

public:

	Manager();
	void showMenu();
	void showpossiblemake();
	int getpassword();
	int getcutline();
	void setcutline(int cutline);
	void showingredient();
	void ingredientorder(string ingredient, int amount);
	void shownetandsale();
	void receiveorder(data_t *data);
	int getsale();
	void customerservice();
	void managermode();
	
};


#endif 

