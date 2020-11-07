/*
 * name.c
 *
 *  Created on: 2017. 10. 10.
 *      Author: IoT-11
 */


#include<stdio.h>

int power(int,int);

int main()
{
int base = 5, exp = 3;

printf("the %dth power of %d is %d.\n ",
		exp, base, power(base, exp));

return 0;

}

int power(int base, int exp)
{
int result, i, x;
result =1, x =1 ;

for(i=1; i<=exp; i++)
    {x=x+1;
	result *=base;}
return result;
}
