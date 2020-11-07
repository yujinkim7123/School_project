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
	cout << "그래픽 에디터입니다.\n";
	GraphicEditor a;
	int i;
	while (true) {
		cout << "삽입:1  삭제:2  모두보기:3  종료:4 >>";
		cin >> i;
		if (i == 1) {
			cout << "선:1, 원:2, 사각형:3 >>";
			int j;
			cin >> j;
			a.input(j);
		}
		else if (i == 2) {
			cout << "삭제하고자 하는 도형의 인덱스>>";
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
			cout << "다시 입력하세요";

	}
	 

}