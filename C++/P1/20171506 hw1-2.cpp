#include <iostream>
using namespace std;

int main() {
	char buf[10000];
	int number[26] = { 0, };
	int i,j;
	int total = 0;

	cout << "���� �ؽ�Ʈ�� �Է��ϼ���. ������׷��� �׸��ϴ�." << "\n";
    cout << "�ؽ�Ʈ�� ���� ; �Դϴ�. 10000������ �����մϴ�.\n";

	cin.getline(buf, 10000, ';');

	for (i = 0; buf[i] != 0; i++) {
		if (isalpha(buf[i])){
			buf[i] = tolower(buf[i]);
			number[buf[i]-97]++;
			total += 1;
		}
	}
	cout << "�� ���ĺ� �� " << total << "\n";
	char a = 'a';
	for (i = 0; i < 26; i++) {

		cout << (char)(a + i) << " (" << number[i] << ") : " ;
		for (j = 0; j < number[i]; j++) {
			cout << '*';
		}
		cout << "\n";
	}
}


		   
		  