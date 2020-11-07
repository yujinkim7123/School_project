#ifndef HW_SERVICE_H
#define HW_SERVICE_H

#include <string>

#define MAX_ITEM 31

typedef struct Item{
    std::string student_name;
    int student_id;
    int grade;                  //  0<=grade<=100
} item_t;

// This function starts the service (return -1 on fail, 0 on success).
int start();    

// This function brings one item from the DB in a random manner (return -1 on fail, 0 on success).
int getItem(item_t& item); 

// This function removes the item corresponding to student_id from the DB
int deleteItem(int student_id);     

// This function returns the total number of students in the DB (1<=number<=31)
unsigned int getNumStudents();   

// Using this function, you can check if your answer is valid or not.
// Please provide your real student_id as a parameter.
std::string checkAnswer(int student_id, int avg);

#endif
