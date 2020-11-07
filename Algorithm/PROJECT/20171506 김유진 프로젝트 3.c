/*
 * hw3.c
 *
 *  Created on: 2018. 5. 10.
 *      Author: kim yu jin
 */

#include<stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100
#define EXPR_SIZE 100

typedef int element;

element stack[STACK_SIZE];

int top = -1;
int isEmpty() {
	if (top == -1)
		return 1;
	else
		return 0;
}

int isFull() {
	if (top == STACK_SIZE - 1)
		return 1;
	else
		return 0;
}

void push(element item) {
	if (isFull()) {
		printf("\n\n Stack is FULL! \n");
		return;
	} else
		stack[++top] = item;
}

element pop() {
	if (isEmpty()) {
		printf("\n\n Stack is Empty!!\n");
		return 0;
	} else
		return stack[top--];
}

element peek() {
	if (isEmpty()) {
		printf("\n\n Stack is Empty !\n");
		return 0;
	} else
		return stack[top];
}

void printStack() {
	int i;
	printf("\n STACK [ ");
	for (i = 0; i <= top; i++)
		printf("%d ", stack[i]);
	printf("] ");
}

int testPair(char* exp) {
	char symbol, open_pair;

	int i, length = strlen(exp);
	top = -1;

	for (i = 0; i < length; i++) {
		symbol = exp[i];
		switch (symbol) {
		case '(':
		case '[':
		case '{':
			push(symbol);
			break;
		case ')':
		case ']':
		case '}':
			if (top == -1)
				return 0;
			else {
				open_pair = pop();

				if ((open_pair == '(' && symbol != ')')
						|| (open_pair == '[' && symbol != ']')
						|| (open_pair == '{' && symbol != '}'))
					return 0;
				else
					break;
			}
		}

	}
	if (top == -1)
		return 1;
	else
		return 0;

}

int precdence(char op) {
	switch (op) {
	case '(':
	case ')':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;

	}

	return -1;
}

void infix_to_postfix(char expr[], char postfix[]) {
	int i = 0, j = 0;
	char op, c;

	while (expr[i] != '\0') {
		c = expr[i++];

		if ((c >= '0' && c <= '9')) {

			postfix[j++] = c;
		} else if (c == '(')
			push(c);
		else if (c == ')') {
			while (isEmpty() == 0) {
				op = pop();

				if (op == '(')
					break;
				else {
					postfix[j++] =' ';
					postfix[j++] = op;

				}

			}
		} else if (c == '+' || c == '-' || c == '*' || c == '/') {
			postfix[j++] =' ';
			while (isEmpty() == 0) {
				op = peek();
				if (precdence(c) <= precdence(op)) {
					postfix[j++] = op;
					postfix[j++] =' ';

					pop();
				} else
					break;
			}
			push(c);
		}
	}
	while (isEmpty() == 0) {
		op = pop();
		postfix[j++] =' ';
		postfix[j++] = op;

	}

	postfix[j] = '\0';
}

element evalPostfix(char *exp) {
	int opr1, opr2, value, i = 0, j= 0;

	int length = strlen(exp);
	char symbol;
	top = -1;
	char temp[100];

	for (i = 0; i < length; i++) {
		symbol = exp[i];
		if (symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/') {
			j =0;
			while ( exp[i] !=' ')
			temp[j++] = exp[i++];
			temp[j] ='\0';
			value = atoi(temp);
			push(value);
		}

		else {
			opr2 = pop();
			opr1 = pop();

			switch (symbol) {
			case '+':
				push(opr1 + opr2);
				break;
			case '-':
				push(opr1 - opr2);
				break;
			case '*':
				push(opr1 * opr2);
				break;
			case '/':
				push(opr1 / opr2);
				break;
			}
			i++;

	}
	}
	return pop();



}
int main(void) {
	int result;
	char input[EXPR_SIZE];
	char postfix[EXPR_SIZE];

	while (1) {
		printf("����� ������ �Է��ϼ���");
		fflush(stdout);
		scanf("%s", input);

		if (testPair(input) != 1) {
			printf("������ �߸��Ǿ����ϴ�.");
			continue;
		}

		infix_to_postfix(input, postfix);
		printf("���� ǥ��� : %s\n", postfix);

		result = evalPostfix(postfix);
		printf("���� ��� => %d\n\n", result);
	}
}
