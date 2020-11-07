#include<iostream>
using namespace std;

class Stack {
	int  top;
	int stack[10];
public:
	Stack() { top = -1; }
	Stack& operator << (int number) {
		if(10 >= top)
		stack[++top] = number;
		return *this; 
	}
    
	bool operator !() {
		if (0 <= top)
			return false ;
		else
			return true;
	}

	void operator >> (int& x) {
		if (0 <= top)
		x = stack[top--];
		
	}
};

int main() {
	Stack stack;
	stack << 3 << 5 << 10;
	while (true) {
		if (!stack)break;
		int x;
		stack >> x;
		cout << x <<' ';
	}
	cout << endl;
}




