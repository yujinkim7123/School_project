#include<iostream>
#include<string>
using namespace std;

class printer {	
	
	string model;
	string manufacturer;
	int printedCount;
	int availableCount;
	
public:
	printer(string model, string manufacturer, int availableCount) {
		this->model = model; this->manufacturer = manufacturer; this->availableCount = availableCount;
	}
	bool print(int pages) {
		printedCount = pages;
		if (availableCount >= printedCount) {
			availableCount = availableCount - printedCount;
			return true;
		}
		else {
			cout << "용지가 부족하여 프린트할 수 없습니다.\n";
			return false;
		}
	}
	int getprintedCount() {return printedCount;}
	int getavailableCount() { return availableCount;}
	string getmodel() { return model; }
	string getmanufacturer() { return manufacturer; }
	~printer() {
		cout << "프린터 본체 종료\n";
	}

};

class InkJetprinter: public printer {
	int availableInk;

public:
	InkJetprinter(string model, string manufacturer, int availableCount, int availableInk) :printer(model, manufacturer, availableCount) {
		this->availableInk = availableInk;
	}
	void printInkJek(int pages) {
		if (print(pages)) {
			if (availableInk >= pages) {
				cout << "프린트 하였습니다.\n";
				availableInk = availableInk - pages;
			}
			else {
				cout << "잉크가 부족하여 프린트 할 수 없습니다.\n";
			}
		}
		
	}
	void show() {
		cout << getmodel() << " ," << getmanufacturer() << " ,남은 종이 " << getavailableCount() << "장 ," << "남은 잉크 " << availableInk <<"\n";
	}
	~InkJetprinter() {
		cout << "잉크프린터를 종료합니다.\n";
	}
};
class Laserprinter : public printer {
	int availableLaser;

public:
	Laserprinter(string model, string manufacturer, int availableCount, int availableLaser) :printer(model, manufacturer, availableCount) {
		this->availableLaser = availableLaser;
	}
	void printLaser(int pages) {
		if (print(pages)) {
			if (availableLaser >= pages) {
				cout << "프린트 하였습니다.\n";
				availableLaser = availableLaser - pages;
			}
			else {
				cout << "토너가 부족하여 프린트 할 수 없습니다.\n";
			}
		}

	}
	void show() {
		cout << getmodel() << " ," << getmanufacturer() << " ,남은 종이 " << getavailableCount() << "장 ," << "남은 토너 " << availableLaser << "\n";
	}
	~Laserprinter() {
		cout << "레이저 프린터를 종료합니다.\n";
	}
};

int main() {
	Laserprinter* Laser = new Laserprinter("sck-6X45", "삼성전자", 3, 20);
	InkJetprinter* Ink = new InkJetprinter("Officejet V40", "HP", 5, 10);
	cout << "현재 작동중인 2 대의 프린터는 아래와 같다.\n";
	cout << "잉크젯 : "; Ink->show();
	cout << "레이저 : "; Laser->show();
	
	while (true) {
		int i, j;
		char  a;
		cout << "프린트(1.:잉크젯, 2.:레이저)와 매수 입력>>";
		cin >> i >> j;
		if (i == 1) {
			Ink->printInkJek(j);
		}
		else if (i == 2) {
			Laser->printLaser(j);
		}
		Ink->show();
		Laser->show();
	    
		cout << "계속 프린트 하시겠습니까(y/n)>>";
		cin >> a;
		if (a == 'y')
			cout << "\n";
		else if (a == 'n')
			break;
		else
			cout << "잘못 입력하였습니다.\n";

	}
	delete Laser;
	delete Ink;
	int end;
	cout << "아무거나 한 문자를 입력시 종료합니다.";
	cin >> end;
	return 0;

}