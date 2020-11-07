#ifndef MANAGER_H
#define  MANAGER_H
#include <string>
using namespace std;

class Manager {

	int password ;
	int cutline; int netprofit; int sale; int negativedebt = 5000;
	int sugar; int milk; int cacao; int coffeebeans; int water;
	string menu[4];
	bool available[4];
public:
	Manager();
	int showMenu();
	void showpossiblemake();
	int getpassword();
	int getcutline();
	void setcutline(int cutline);
	void showingredient();
	void ingredientorder(string ingredient, int amount);
	void shownetandsale();
	void receiveorder(string menu);
	int getsale();
	void start();
};


#endif 

