#include<iostream>
#include<string.h>
#include<unistd.h>
#include "hw_service.h"
using namespace std;

typedef struct DATA{
  int grade;
  char str[30];
  int id;
}data_t;


void parentprocess(int pipe1[], int pipe2[]){
close(pipe1[0]);
close(pipe2[1]);

data_t item1[31];
int num;
int ch;
int avg = 0;
char result[100];
read(pipe2[0], &item1, sizeof(data_t)*31);
read(pipe2[0], &ch, 4);
for(int i = 0; i < ch; i++){
  avg = avg + item1[i].grade;
  }
avg = avg/ch;
write(pipe1[1], &avg, 4);
read(pipe2[0], &result, sizeof(result));
cout << result << "\n";
  
}

void childprocess(int pipe1[], int pipe2[]){
  close(pipe1[1]);
  close(pipe2[0]);
  int num1;
  int num2;
  int avg1;
  int student = 0;
  int  check = 0;
  char a[100];
  item_t nowitem;
  data_t item[31];
  
    start();
    num2 = getNumStudents();
    while(student < num2){
    check = getItem(nowitem);
    if(check == 0){
   item[student].grade = nowitem.grade;
   item[student].id = nowitem.student_id;
   strcpy(item[student].str, nowitem.student_name.c_str());
   student++;
   deleteItem(nowitem.student_id);
     } 
  }

   write(pipe2[1], &item, sizeof(data_t)*31);
   write(pipe2[1], &num2, 4);
   read(pipe1[0], &avg1, 4);
    strcpy(a , checkAnswer(20171506, avg1).c_str());
    write(pipe2[1], &a, sizeof(a));
  }                
  

int main(){
int pipe1[2], pipe2[2];
pipe(pipe1);
pipe(pipe2);

pid_t pid = fork();

switch(pid){
case -1:
return -1;
case 0:
childprocess(pipe1, pipe2);
break;
default:
parentprocess(pipe1, pipe2);
break;
  }

}