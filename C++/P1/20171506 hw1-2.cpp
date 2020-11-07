#include <iostream>
using namespace std;

int main() {
	char buf[10000];
	int number[26] = { 0, };
	int i,j;
	int total = 0;

	cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다." << "\n";
    cout << "텍스트의 끝은 ; 입니다. 10000개까지 가능합니다.\n";

	cin.getline(buf, 10000, ';');

	for (i = 0; buf[i] != 0; i++) {
		if (isalpha(buf[i])){
			buf[i] = tolower(buf[i]);
			number[buf[i]-97]++;
			total += 1;
		}
	}
	cout << "총 알파벳 수 " << total << "\n";
	char a = 'a';
	for (i = 0; i < 26; i++) {

		cout << (char)(a + i) << " (" << number[i] << ") : " ;
		for (j = 0; j < number[i]; j++) {
			cout << '*';
		}
		cout << "\n";
	}
}


		   
		  