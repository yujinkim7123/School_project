/*
 * name.c
 *
 *  Created on: 2017. 11. 17.
 *      Author: HP
 */

#include <stdio.h>

int main(void){
	char arr[] = "hello, world!";
	char str[100];
	int len, i;
	char *p;

	len = sizeof(arr);
	p = arr + len -2;

	for(i = 0; i <len ; i++)
	{ str[i] = *p--;}

	str[len-1] = '\0';



 printf("%s\n", arr);
 printf("%s\n", str);


}
