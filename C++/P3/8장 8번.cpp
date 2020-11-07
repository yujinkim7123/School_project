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
			cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�.\n";
			return false;
		}
	}
	int getprintedCount() {return printedCount;}
	int getavailableCount() { return availableCount;}
	string getmodel() { return model; }
	string getmanufacturer() { return manufacturer; }
	~printer() {
		cout << "������ ��ü ����\n";
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
				cout << "����Ʈ �Ͽ����ϴ�.\n";
				availableInk = availableInk - pages;
			}
			else {
				cout << "��ũ�� �����Ͽ� ����Ʈ �� �� �����ϴ�.\n";
			}
		}
		
	}
	void show() {
		cout << getmodel() << " ," << getmanufacturer() << " ,���� ���� " << getavailableCount() << "�� ," << "���� ��ũ " << availableInk <<"\n";
	}
	~InkJetprinter() {
		cout << "��ũ�����͸� �����մϴ�.\n";
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
				cout << "����Ʈ �Ͽ����ϴ�.\n";
				availableLaser = availableLaser - pages;
			}
			else {
				cout << "��ʰ� �����Ͽ� ����Ʈ �� �� �����ϴ�.\n";
			}
		}

	}
	void show() {
		cout << getmodel() << " ," << getmanufacturer() << " ,���� ���� " << getavailableCount() << "�� ," << "���� ��� " << availableLaser << "\n";
	}
	~Laserprinter() {
		cout << "������ �����͸� �����մϴ�.\n";
	}
};

int main() {
	Laserprinter* Laser = new Laserprinter("sck-6X45", "�Ｚ����", 3, 20);
	InkJetprinter* Ink = new InkJetprinter("Officejet V40", "HP", 5, 10);
	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����.\n";
	cout << "��ũ�� : "; Ink->show();
	cout << "������ : "; Laser->show();
	
	while (true) {
		int i, j;
		char  a;
		cout << "����Ʈ(1.:��ũ��, 2.:������)�� �ż� �Է�>>";
		cin >> i >> j;
		if (i == 1) {
			Ink->printInkJek(j);
		}
		else if (i == 2) {
			Laser->printLaser(j);
		}
		Ink->show();
		Laser->show();
	    
		cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
		cin >> a;
		if (a == 'y')
			cout << "\n";
		else if (a == 'n')
			break;
		else
			cout << "�߸� �Է��Ͽ����ϴ�.\n";

	}
	delete Laser;
	delete Ink;
	int end;
	cout << "�ƹ��ų� �� ���ڸ� �Է½� �����մϴ�.";
	cin >> end;
	return 0;

}