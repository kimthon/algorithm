#include<iostream>
#include<string>
#include<vector>
#include<climits>
#include<map>

using namespace std;

void setMap(map<int,int> &m, int num, int v) {
	if(v > 8) return;
	if(num <= 0) return;

	if(m.find(num) != m.end()) {
		if(v < m[num]) cout << num << ':' << m[num] << "->" << v << " modified" << endl;
		m[num] = min(m[num], v);
	}
	else {
		cout << num << ':' << v << " added" << endl;
		m[num] = v;
	}
}

int solution(int N, int num) {
	map<int,int> m;
	if(num == 0) return 2;

	int c = 0;
	for(int i = 1; i <= 8; ++i) {
		c = c*10 + N;
		setMap(m, c, i);

		for(const pair<int, int> &a : m) {
			for(const pair<int, int> &b : m) {
				int v = a.second + b.second;
				setMap(m, b.first + a.first, v);
				setMap(m, b.first - a.first, v);
				setMap(m, b.first * a.first, v);
				setMap(m, b.first / a.first, v);
			}
		}
	}

	if(m.find(num) != m.end()) return m[num];
	return -1;
}

int main() {
	int N, num;

	cout << "사용할 숫자를 넣어주세요 : "; 
	cin >> N;

	cout << "만들 숫자를 넣어주세요 : ";
	cin >> num;

	cout << solution(N, num) << endl;

	return 0;
}
