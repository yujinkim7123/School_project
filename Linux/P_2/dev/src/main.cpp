#include<iostream>
using namespace std;
#include "../inc/Customer.h"
#include "../inc/Manager.h"

int main() {
	Customer customermode;
	Manager managermode;
	string i, j;
	
	while (true) {
		cout << "****************Machine Start***************\n\n";
		cout << '\t' << "1. Customer Mode\n";
		cout << '\t' << "2. Manager Mode\n";
		cout << '\t' << "3. Machine end\n";
		cout <<  "\nplease choose mode(please enter a number in the view)\n";
		cin >> i;
		if (i.compare("1") == 0) {
			if (managermode.getcutline() <= managermode.getsale()) {
				cout << "Target Sale Achievement\n";
				cout << "business end\n";
			}
			else
			customermode.start(managermode);
	
		}
		else if (i.compare("2") == 0) {
			int password;

			cout << "input password\n";
			cin >> j;
			if (atoi(j.c_str()) != 0 || j.compare("0") == 0) {
				password = atoi(j.c_str());
				if (password == managermode.getpassword()) {
					managermode.start();
				}
				else {
					cout << "Incorrect input password\n";
				}
			}
			else {
				cout << "Incorrect input password\n";
			}
		}

		else if (i.compare("3") == 0) {
			break;
		}

		else
			cout << "you've entered something wrong\n";

	}
	cout << "************************Machine end***************************\n";
}
