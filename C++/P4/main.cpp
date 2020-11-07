#include "Shape.h"
#include "Circle.h"
#include "Line.h"
#include "Rect.h"
#include <vector>
#include <iostream>
using namespace std;

class  GraphicEditor {
	vector<Shape *> v;
public:
	
	void show() {
		
		for (unsigned int i = 0; i < v.size(); i++) {
			cout << i << ": "; v[i]->paint(); 
		}
	}

	void delet(int index) {
		vector<Shape *>::iterator it;
		it = v.begin();
		for (int i = 0; i < index; i++) {
			it++;
		}
		v.erase(it);
	}
	void input(int chioce) {
		if(chioce == 1)
		v.push_back(new Line());
		else if (chioce == 2)
		v.push_back(new Circle());
		else if(chioce == 3)
		v.push_back(new Rect());

	}

};

int main() {
	cout << "�׷��� �������Դϴ�.\n";
	GraphicEditor a;
	int i;
	while (true) {
		cout << "����:1  ����:2  ��κ���:3  ����:4 >>";
		cin >> i;
		if (i == 1) {
			cout << "��:1, ��:2, �簢��:3 >>";
			int j;
			cin >> j;
			a.input(j);
		}
		else if (i == 2) {
			cout << "�����ϰ��� �ϴ� ������ �ε���>>";
			int j;
			cin >> j;
			a.delet(j);
		}
		else if (i == 3) {
			a.show();
		}
		else if (i == 4)
			break;

		else
			cout << "�ٽ� �Է��ϼ���";

	}
	 

}