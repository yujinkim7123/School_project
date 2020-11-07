#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class Player {
	string member[2];
public :
	void setname() {
		cout << "ù��° ���� �̸�>>";
		getline(cin, member[0],'\n');
		cout << "�ι�° ���� �̸�>>";
		getline(cin, member[1],'\n');		
	}
	void playname(int number) {
		if (number > 1) 
			number = 0;
    	if (number == 0) cout << member[0] << ":<Enter>";
		else if (number == 1) cout << member[1] << ":<Enter>";

	}
	string getname(int number) {
		return member[number];
	}
};


class GamblingGame {
	string a;
	int random[3];
	int number = 0;
public:
	GamblingGame() {
		cout << "***** �׺� ������ �����մϴ�. *****" << endl;
		srand((unsigned)time(0));
	}
	void gamestart() {
		Player set;
		set.setname();
		while (true) {
			set.playname(number);
			getline(cin,a);
			setrandom();
			cout << "\t\t" << random[0] << "\t" << random[1] << "\t" << random[2] << "\t";
			if (random[0] == random[1] && random[0] == random[2])
			{
				cout << set.getname(number) << "�� �¸�!!" << endl;
				break;
			}
			else
				cout << "�ƽ�����!"<<endl;
			    number++;
				if (number > 1) number = 0;
 		}
	}

	void setrandom() {
		
		for (int i = 0; i < 3; i++) {
			
			random[i] = rand() % 3;
		}
	}

};

int main() {
	GamblingGame game;
	game.gamestart();

	return 0;
}