#include<iostream>
#include<string>
#include<vector>

using namespace std;

string solution(string number, int k) {
	for(int i = 0; i < k; ++i) {
		int c = 1;
		char pre = number[0];
		int size = number.length();
		for(; c < size; ++c) {
			if(pre < number[c]) break;
			pre = number[c];
		}

		if(c != size) number = number.substr(0, c - 1) + number.substr(c);
		else number = number.substr(0, c - 1);
	}

	return number;
}

int main() {
	string number;
	int k;
	cout << "입력할 숫자 : ";
	cin >> number;
	cout << "삭제할 갯수 : ";
	cin >> k;

	cout << solution(number, k) << endl;

	return 0;
}
