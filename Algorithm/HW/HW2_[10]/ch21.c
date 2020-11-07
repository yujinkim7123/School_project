/*
 * hello.c
 *
 *  Created on: 2018. 3. 21.
 *      Author: kim yu jin
 */
#include <stdio.h>
#include <stdlib.h>
int main(){
	char *A = (char *)malloc(sizeof(char)*100);

	int i;
	printf("문자열을 입력하시오");
	fflush(stdout);
	scanf("%s", A);


	i = 0;
	while( *(A + i) != '\0' ){
		if( 65 <= *(A + i)&& *(A + i) <= 90 )
		{*(A +i) = *(A + i) +32;
		i++;}
		else
		{*(A +i) = *(A + i) -32;
		i++;}
	}

	printf("%s", A);
    free(A);
}
