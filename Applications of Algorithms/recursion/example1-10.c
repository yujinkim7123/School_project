#include<stdio.h>


int factorial(int n) {
	if (n <= 1)
		return 1;
	else
		return n * factorial(n - 1);
}

double power(double x, int n) {
	if (n == 0)
		return 1;
	else
		return x * power(x, n - 1);
}


int fibonacci(int n) {

	if (n < 2)
		return n;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);

}
int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);

}

int length(char *str) {
	if (*str == '\0')
		return 0;
	else
		return 1 + length(str + 1);
}

void printChars(char *str) {
	if (*str == '\0')
		return;
	else {
		printf("%c", *str);
		printChars(str + 1);
	}
}

void printCharReverse(char *str) {
	if (*str == '\0')
		return;
	else {
		printCharReverse(str + 1);
		printf("%c", *str);

	}

}

int search(int data[], int n, int target) {
	if (n <= 0)
		return -1;
	else if (target == data[n - 1])
		return n - 1;
	else
		return search(data, n - 1, target);
}

int max(int data, int data2) {

	if (data >= data2)
		return data;
	else
		return data2;
}



int findMax(int n, int data[]) {
	if (n == 1)
		return data[0];
	else
		return max(data[n - 1], findMax(n - 1, data));
}

void printInBinary(int n) {
	if (n < 2)
		printf("%d", n);
	else {
		printInBinary(n / 2);
		printf("%d", n % 2);

	}
}

int main() {

	char str[12] = { "abcdefgtijk" };
	int  str2[10] = { 1,2,3,4,5,6,7,8,9 ,10 };

	printf("%d\n", factorial(4));

	printf("%f\n", power(4, 2));

	printf("%d\n", fibonacci(6));

	printf("%d\n", gcd(48, 21));

	printf("%d\n", length(str));

	printChars(str);

	printf("\n");

	printCharReverse(str);

	printf("\n");

	printf("%d\n", search(str2, 10, 10));

	printf("%d\n", findMax(10, str2));

	printInBinary(13);


}



