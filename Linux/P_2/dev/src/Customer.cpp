#include <iostream>
using namespace std;
#include "../inc/Customer.h"

void Customer::start(Manager& managercall) {
		string i;
		
		while (managercall.getcutline() > managercall.getsale()) {
		cout << "\n\n*****************customer mode***************\n";
		cout << "\t" << "1. The Menu(orderable)\n";
		cout << "\t" << "2. Order\n";
		cout << "\t" << "3. Customer Mode end\n";
		cout << "\nplease select a service(enter number)\n";
		cin >> i;

		if (i.compare("1") == 0) {
			string a;
		if(showmenu(managercall) != 0);
		else{
                    cout << "there is no orderable menu\n\n";
		}
		cin.ignore();
		cout << "\nClick 'y' to return to the Manager page.(input y)\n";
		while (true) {
			getline(cin, a, '\n');
			if (a.compare("y") == 0) {
				break;
			}
			else {
				cout << "please input 'y'\n";
			}
		}
		}
		else if (i.compare("2") == 0) {
			string yn;
			while (true) {
				if (managercall.getcutline() > managercall.getsale()) {
					if (showmenu(managercall) != 0) {
						cout << endl << "would you like to order?(y/n please enter)\n";
						cin >> yn;
						if (yn.compare("y") == 0 || yn.compare("Y") == 0) {
							menuorder(managercall);
						}
						else if (yn.compare("n") == 0 || yn.compare("N") == 0) {
							break;
						}
						else {
							cout << "you've entered something wrong\n";
							cout << "please enter y and n \n";
						}
					}
					else {
						cout << "there is no menu available for ordering because the material is out of stock\n";
						break;
					}
				}
				else {
					cout << "Target Sale Achievement\n";
					cout << "business end\n";
					break;
				}
			
	
		}
    }
		else if (i.compare("3") == 0) {
			break;
		}
		else {
			cout << "you've entered something wrong\n";
		}
  }
}

int Customer::showmenu(Manager& managercall) {
    int number;  
    number = managercall.showMenu();
   return number;

};
void Customer::menuorder(Manager& managercall) {
	string  menu;
	cout << "what would you like to order?(please enter a menu name)\n";
	cin >> menu;
        	managercall.receiveorder(menu);

		
};
