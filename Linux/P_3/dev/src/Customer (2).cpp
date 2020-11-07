//#include <iostream>
#include "../inc/Customer.h"
//#include "../inc/common.h"
//using namespace std;
/*#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string>
#include<string.h>
#define FIFO_NAME "res/my_fifo"*/

void Customer::start() {
int server_fifo_fd, client_fifo_fd;
int open_mode_server ,open_mode_client;
int res;
char a;
char choice;
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
open_mode_server = O_WRONLY|O_NONBLOCK;
open_mode_client = O_RDONLY;
	while(true){
		open_mode_server = O_WRONLY|O_NONBLOCK;
        data.areyouclosed = 0;
	cout << "go into a store?\n";
	cout << "please press anything>>";
	 cin >> i;
	cout << "\n\n";
		a = '4';
		server_fifo_fd = open(SERVER_FIFO_NAME, open_mode_server);
	    if(server_fifo_fd != -1){
		write(server_fifo_fd, &a, 1);
		close(server_fifo_fd); 
		client_fifo_fd = open(CLIENT_FIFO_NAME, open_mode_client);
		read(client_fifo_fd, &data, sizeof(data_t));
	    close(client_fifo_fd);
		if(client_fifo_fd != -1 ){
		while (true) {
			if(data.areyouclosed == 1 ){
		cout << "\n\n*****************customer mode***************\n";
		cout << "\t" << "1. The Menu(orderable)\n";
		cout << "\t" << "2. Order\n";
		cout << "\t" << "3. Customer Mode end\n";
		cout << "\nplease select a service(enter number)\n";
		cin >> i;

        choice = i.at(0);
        open_mode_server = O_WRONLY;
		if (i.compare("1") == 0) {
			server_fifo_fd = open(SERVER_FIFO_NAME, open_mode_server);
			write(server_fifo_fd, &choice, 1);
			close(server_fifo_fd);
		  if(showmenu() > 0);
		   else
           cout << "there is no orderable menu\n\n";
		cin.ignore();
		cout << "\nClick 'y' to return to the Manager page.(input y)\n";
		while (true) {
			string a;
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
		a = '4';
		server_fifo_fd = open(SERVER_FIFO_NAME, open_mode_server);
		write(server_fifo_fd, &a, 1);
		close(server_fifo_fd);
		client_fifo_fd = open(CLIENT_FIFO_NAME, open_mode_client);
		read(client_fifo_fd, &data, sizeof(data_t));
	    close(client_fifo_fd);
		if (data.areyouclosed == 1) {
					a = '1';
				server_fifo_fd = open(SERVER_FIFO_NAME, open_mode_server);
	        	write(server_fifo_fd, &a, 1);
		        close(server_fifo_fd);
					if (showmenu() > 0) {
						cout << endl << "would you like to order?(y/n please enter)\n";
						cin >> yn;
						if (yn.compare("y") == 0 || yn.compare("Y") == 0) {
					     server_fifo_fd = open(SERVER_FIFO_NAME, open_mode_server);
	        	         write(server_fifo_fd, &choice, 1);
		                 close(server_fifo_fd);
				        	menuorder();
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
					cout << "***Target Sale Achievement***\n";
					cout << "***business end**************\n\n";
					break;
				}	
	     }	    
      }

	else if (i.compare("3") == 0) {
		 server_fifo_fd = open(SERVER_FIFO_NAME, open_mode_server);
	     write(server_fifo_fd, &choice, 1);
		 close(server_fifo_fd);
		break;
		}
    else {
			cout << "you've entered something wrong\n";
		}
    
    } 

	else{
		break;

	}

  }
		}
		}
	else{
		cout << "***business preparation***\n\n";
		 close(server_fifo_fd);
	}

}
  
}
int Customer::showmenu(){
int client_fifo_fd;
int open_mode_client = O_RDONLY;
data_t data;
 client_fifo_fd = open(CLIENT_FIFO_NAME, open_mode_client);
	cout << "\n\n";
	cout << "\t" << "<Menu>\n";
if(client_fifo_fd != -1){
	int check;
    check = read(client_fifo_fd, &data, sizeof(data_t));
    if(check > 0 && data.number > 0){
    for(int i = 0; i < data.number; i++)
    cout << data.menu[i];
	  } 
	}
  close(client_fifo_fd);
  return data.number;
}
void Customer::menuorder() {
	int server_fifo_fd, client_fifo_fd;
    int open_mode_client = O_RDONLY;
    int open_mode_server = O_WRONLY | O_NONBLOCK;
	data_t data;
		server_fifo_fd = open(SERVER_FIFO_NAME, open_mode_server);

	if(server_fifo_fd != -1){
	string  menu;
	cout << "what would you like to order?(please enter a menu name)\n";
    cin >> menu;
		strcpy(data.menuchoice, menu.c_str());
        write(server_fifo_fd, &data, sizeof(data_t));
		close(server_fifo_fd);	
	}
		client_fifo_fd = open(CLIENT_FIFO_NAME, open_mode_client);
		if(client_fifo_fd != -1){
          read(client_fifo_fd, &data, sizeof(data_t));
		  cout << data.log;
		  close(client_fifo_fd);
		}
}
