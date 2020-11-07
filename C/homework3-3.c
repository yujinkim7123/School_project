/*
 * name.c
 *
 *  Created on: 2017. 10. 10.
 *      Author: IoT-11
 */


#include <stdio.h>

void getmax(void);
void getmin(void);
float a,b,c, max, min;

int main (void)
{
a = 3.5, b = -4.5, c = 2.3e-1, max = min =0;
getmax(); getmin();
printf("Max number is %f.\n", max);
printf("Min number is %f.\n", min);

return 0;
}

void getmax(void)
{
if(a<b)
{if(c<b)
    max = b;
  else
	max = c;}
else
    max = a;
}

void getmin(void)
{
if(a<b)
{if(a<c)
	min = a;
 else
	min = c;}
else
	min = b;
}

