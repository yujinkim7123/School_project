/*
 * hello.c
 *
 *  Created on: 2018. 3. 21.
 *      Author: kim yu jin
 */
#include <stdio.h>

int main() {
	char str[2][100];
	int i, y, x = 0;
	for (i = 0; i < 2; i++) {
		printf("문자열을 입력하세요");
		fflush(stdout);
		scanf("%s", str[i]);
	}
	if (str[0] == '\0' && str[1] == '\0')
		printf("입력하지 않았습니다");


    i = 0;
    y = 0;
	while (str[0][i] != '\0') {
		if (str[1][i] == '\0')
			{y = 1;
		    break;}

		if (str[0][i] == str[1][i])
			i++;

		else {
			y = 1;
			break;
		}
	    }

	if (str[1][i] == '\0' && str[0][i] == '\0')
		x = -1;
	else
		y = 1;

    if (y == 0 && x == -1)
		printf("같습니다");
	else
		printf("같지 않습니다");
}

