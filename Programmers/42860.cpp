#include<iostream>
#include<string>
#include<vector>

using namespace std;

int solution(string name) {
	int answer = 0;
	int size = name.length();

	// 각 자리에서 조이스틱 움직이는 횟수 더해주기
	for(char &c : name) {
		int add = (c > 'N')? 'Z' - c + 1 : c - 'A';
		answer += add;
	}

	// 최소 좌우 이동거리
	int move = size - 1;
	for(int i = 0; i < size; ++i) {
		if(name[i] == 'A') {
			int s = i;
			while(name[++i] == 'A');
			--i;

			int l = size - 1 - i;
			int r = s - 1;	

			int lr = min(2*l + r, 2*r +l);
			move = min(move, lr);
		}
	}

	return answer + move;
}

int main() {
	string name;
	cin >> name;

	cout << solution(name) << endl;

	return 0;
}
