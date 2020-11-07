#include "../inc/Manager.h"

void Manager::managermode() {
	while(true){
	string a;
	cout << "Customer service(n), manager mode(y)\n";
    cin >> a;
	if(a.compare("y") == 0){
	while (true){
		string i;
		cout << "\n\n*****************Manager mode**************\n";
		cout << "Target amount remaining : " << cutline - sale << "\n";
		cout << "Target amount : " << cutline << "\n";
		cout << "your money : " << negativedebt << "\n\n";
		cout << "\t" << "1. Material Check\n";
		cout << "\t" << "2. Material Order\n";
		cout << "\t" << "3. Createable menu\n";
		cout << "\t" << "4. a net profit and Sale Check\n";
		cout << "\t" << "5. End of business Amount setting\n";
		cout << "\t" << "6. Manager mode end\n";
		cout << "\nplease select a service(enter number)\n";
		cin >> i;

		if (i.compare ("1") == 0) {
			string a;
			showingredient();
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
			string name, quantity; int q;
			cout << "\t" << "<Material Order>\n";
			cout << "\t" << "sugar"<<"\t\t"<<"Price:500"<<"\n";
			cout << "\t" << "milk" <<"\t\t"<<"Price:1000" <<"\n";
			cout << "\t" << "cacao" <<"\t\t"<<"Price:1000" <<"\n";
			cout << "\t" << "coffeebeans" <<"\t"<<"Price:1500"<< "\n";
			cout << "\t" << "water" <<"\t\t"<<"Price:500"<<"\n";
		     while(true){
		     string yn;
             cout <<"\nwould you like to order?(input y/n)";
			 cin >> yn;
			 if(yn.compare("y") == 0 || yn.compare("Y") == 0){
			  cout << "\nwhat would you like to order?(please write down the name in the view)\n";
			  cin >> name;
			  cout << "\nhow much would you like to order?(please enter the quantity)\n";	
			  cin >> quantity;
			int j = 0; int check = 0; int num = 0;
			 while(quantity[j] != '\0'){
                        if(isdigit(quantity[j]) != 0);
                             else check = 1;
                                 j++;
                              }
			if ((num = atoi(quantity.c_str()) != 0) && check == 0 && num > 0){
				q = atoi(quantity.c_str());
				ingredientorder(name, q);
			   }
			else {
				cout << "you've entered something wrong\n";
				cout << "please enter the quantity in numbers\n";
			}
		     }
           else if(yn.compare("n") == 0 || yn.compare ("N") == 0) {
	            break;   	     
		     }
			 else{
                        cout << "you've entered something wrong\n";
						cout << "please enter y and n \n";

			 }
	      
                    }
			
		}
		else if (i.compare("3") == 0) {
			string a;
			showpossiblemake();
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
		else if (i.compare("4") == 0) {
			string a;
			shownetandsale();
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
		else if (i.compare("5") == 0) {
			string yn;
			string entercutline; int e;
				cout << "do you want to set terget amount?(input y/n)\n";
				cin >> yn;
				if (yn.compare("y") == 0 || yn.compare("Y") == 0) {
					cout << "input set setcutline(Don't input O, only input number)\n";
					cin >> entercutline;
					int check1 = 0; int j = 0; 
					while (entercutline[j] != '\0') {
						if (isdigit(entercutline[j]) != 0);
						else check1 = 1;
						j++;
					}
					if (check1 == 0 ) {
						e = atoi(entercutline.c_str());
						if (e > 0) {
							setcutline(e);
						}
						else {
							cout << "you've entered something wrong\n";
							cout << "please enter an amount excluding zero\n";
						}
					}
					else {
						cout << "you've entered something wrong\n";
						cout << "please enter an amount excluding zero\n";
					}
				}
				else if (yn.compare("n") == 0 || yn.compare("N") == 0) {
					break;
				}
				else {
					cout << "you've entered something wrong\n";
					cout << "please enter y and n \n";

				}
		   }
		
		else if (i.compare("6") == 0) {
			break;
		}
		else {
			cout << "you've entered something wrong\n";
			cout << "please select the number in the view\n";
		}
	}
}
else{
	if(cutline > sale){
	cout << "a customer service\n";
    customerservice();}
	else{
		cout << "Target Sale Achievement\n";
	}
	
}
	}
}
 void Manager::customerservice(){
int server_fifo_fd, client_fifo_fd;
int open_mode_server ,open_mode_client;
int res;
char a;
data_t data;
string i;

if(access(SERVER_FIFO_NAME, F_OK)==-1){
	res = mkfifo(SERVER_FIFO_NAME, 0777);
	if(res != 0){ exit(-1); }
	}
if(access(CLIENT_FIFO_NAME, F_OK)==-1){
	res = mkfifo(CLIENT_FIFO_NAME, 0777);
	if(res != 0){ exit(-1); }
	}
open_mode_server = O_RDONLY;
open_mode_client = O_WRONLY;

	while(true){
	int check = 0;
	server_fifo_fd = open(SERVER_FIFO_NAME, open_mode_server);
	if(server_fifo_fd != -1){
     check = read(server_fifo_fd, &a, 1);
       
	   if(check > 0 && a == '1'){
		  close(server_fifo_fd);
		  showMenu();
	   }

	 else if(check > 0 && a == '2'){
		check = read(server_fifo_fd, &data, sizeof(data_t));
		close(server_fifo_fd);
		if(check > 0){
		 receiveorder(&data);
	 }
	}
	else if(check > 0 && a == '4'){
		close(server_fifo_fd);
		client_fifo_fd = open(CLIENT_FIFO_NAME, open_mode_client);
	data.areyouclosed = 1;
	if(cutline > sale){
		write(client_fifo_fd, &data, sizeof(data_t));
		close(client_fifo_fd);}
    else{
         data.areyouclosed = -1;
		 write(client_fifo_fd, &data, sizeof(data_t));
		 cout << "Target Sale Achievement\n";
		  close(client_fifo_fd);	
	      break;
    }
	}
	else{
	 close(server_fifo_fd);
	break;
	}
   }
  } 
 }
Manager::Manager() {
	password = 123;
	cutline = 10000; netprofit = 0; sale = 0; negativedebt = 5000;
	sugar = 3; milk = 3; cacao = 3; coffeebeans = 3; water = 3;
	menu[0] = "cocoa"; menu[1] = "americano"; menu[2] = "mocha latte"; menu[3] = "milktea";
	available[0] = false; available[1] = false; available[2] = false; available[3] = false;
}
void Manager::showpossiblemake() { 
	cout << "\t" << "<Createable menu>\n";
	if (water > 0) {
		if (cacao > 0) {
			cout << "\t" << "cocoa\n";
		}
		if (coffeebeans > 0)
			cout << "\t" << "americano\n";
	}
	if (milk > 0 && sugar > 0) {
		cout << "\t" << "mocalatte\n";
		if(coffeebeans > 0)
		cout << "\t" << "milktea\n";
	}
}

void Manager::showMenu(){
int client_fifo_fd;
int open_mode_client;
open_mode_client = O_WRONLY;
client_fifo_fd = open(CLIENT_FIFO_NAME, open_mode_client);
data_t data;

 if(client_fifo_fd != -1){
	int conter = 0;
	if (water > 0) {
		if (cacao > 0) {
			strcpy(data.menu[data.number++], "cocoa\t\tPrice:1000\n");
			available[0] = true;
		}
		else {
			available[0] = false;
		}
		if (coffeebeans > 0 ) {
			strcpy(data.menu[data.number++],"americano\tPrice:1500\n");
			available[1] = true;
		}
		else {
			available[1] = false;
		}
	}
	if (milk > 0 && sugar > 0) {
		strcpy(data.menu[data.number++],"milktea\t\tPrice:2000\n");
		available[2] = true;
		if (coffeebeans > 0) {
		strcpy(data.menu[data.number++],"mocalatte\tPrice:2000\n");
		available[3] = true;
		}
		else {
			available[3] = false;
		}
	}
	else {
		available[2] = false;
	}

    write(client_fifo_fd, &data, sizeof(data_t));
	close(client_fifo_fd);
  }
}

int Manager::getpassword() { return password; };
int Manager::getcutline() { return cutline; };
void Manager::setcutline(int cutline)
{ 
  this->cutline = cutline; 
  cout << "Setup completed\n"; 
}
void Manager::showingredient() {
	cout << "\n";
	cout << "\t" << "<Material Check>\n";
	cout << "\t" << "sugar: " << sugar << "\n";
	cout << "\t" << "milk: " << milk << "\n";
	cout << "\t" << "cacao: " << cacao << "\n";
	cout << "\t" << "coffeebeans: " << coffeebeans << "\n";
	cout << "\t" << "water: " << water << "\n";
}
void Manager::ingredientorder(string ingredient, int amount) {
	if (negativedebt >= 500* amount) {
		if (ingredient.compare("sugar") == 0) {
			sugar = sugar + amount;
			netprofit = netprofit - (500 * amount);
			negativedebt = negativedebt - (500 * amount);
			cout << "Order complete\n";
		}
		else if (ingredient.compare("water") == 0) {
			water = water + amount;
			netprofit = netprofit - (500 * amount);
			negativedebt = negativedebt - (500 * amount);
			cout << "Order complete\n";
		}

		else if (ingredient.compare("milk") == 0) {
			if (negativedebt >= 1000* amount) {
				milk = milk + amount;
				netprofit = netprofit - (1000 * amount);
				negativedebt = negativedebt - (1000 * amount);
				cout << "Order complete\n";
			}
			else
				cout << "you don't have enough money\n";
		}
		else if (ingredient.compare("cacao") == 0) {
			if (negativedebt >= 1000*amount) {
				cacao = cacao + amount;
				netprofit = netprofit - (1000 * amount);
				negativedebt = negativedebt - (1000 * amount);
				cout << "Order complete\n";
			}
			else
				cout << "you don't have enough money\n";

		}

		else if (ingredient.compare("coffeebeans") == 0) {
			if (negativedebt >= 1500 * amount) {
				coffeebeans = coffeebeans + amount;
				netprofit = netprofit - (1500 * amount);
				negativedebt = negativedebt - (1500 * amount);
				cout << "Order complete\n";
			}
			else
				cout << "you don't have enough money\n";
		}
		else {
			cout << "this is not an orderable material.";
		}
	}
		else
			cout << "you don't have enough money\n";	
}
void Manager::shownetandsale(){
	cout << "\t" << "<a net profit and Sale Check>\n";
	cout << "\t" << "net profit: " << netprofit << "\n";
	cout << "\t" << "sale: " << sale << "\n";
}
void Manager::receiveorder(data_t *data) {
 int client_fifo_fd;
int open_mode_client;
open_mode_client = O_WRONLY;
client_fifo_fd = open(CLIENT_FIFO_NAME, open_mode_client);
int check = 0;

	if(client_fifo_fd != -1){
	if (strcmp(data->menuchoice,"cocoa") == 0) {
		if (available[0] == true) {
			cacao--;
			water--;
			sale = sale + 1000;
			netprofit = netprofit + 1000;
			negativedebt = negativedebt + 1000;
		}
		else {
			check = -1;
		}
	}
	else if (strcmp(data->menuchoice,"americano")==0 || strcmp(data->menuchoice,"Americano") == 0) {
		if (available[1] == true) {
			coffeebeans--;
			water--;
			sale = sale + 1500;
			netprofit = netprofit + 1500;
			negativedebt = negativedebt + 1500;
		}
		else {
			check = -1;
		}
	}
		
	else if (strcmp(data->menuchoice,"milktea") == 0) {
		if (available[2] == true) {
			sugar--;
			milk--;
			sale = sale + 2000;
			netprofit = netprofit + 2000;
			negativedebt = negativedebt + 2000;
		}
		else {
			check = -1;
		}
	}
	else if (strcmp(data->menuchoice,"mocalatte") == 0) {
		if (available[3] == true) {
			milk--;
			sugar--;
			coffeebeans--;
			sale = sale + 2000;
			netprofit = netprofit + 2000;
			negativedebt = negativedebt + 2000;
		}
		else {
			check = -1;
		}
	}
	
	else{ check = -2;}
		if(check == 0){
        strcpy(data->log, "Order complete\n");
		}
		else if(check == -1){
	    strcpy(data->log, "there is no orderable\n");
		}
		else{
        strcpy(data->log, "No menu\n");
		}
		  write(client_fifo_fd , data,  sizeof(data_t));
		  close(client_fifo_fd );
	}
}

int Manager::getsale() {return sale;}
