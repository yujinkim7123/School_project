#ifndef COMMON_H
#define COMMON_H
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string>
#include<string.h>
#include <iostream>
using namespace std;

#define SERVER_FIFO_NAME "res/s_fifo"
#define CLIENT_FIFO_NAME "res/c_fifo"

typedef struct DATA{
    char menu[4][100];
    int areyouclosed = 1;
    int number = 0; 
    char menuchoice[50];
    char log[50];
}data_t;

#endif 