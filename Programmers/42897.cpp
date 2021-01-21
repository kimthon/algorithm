#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int solution(vector<int> money) {
	int size = (int)money.size();
	vector<int> m1(size, 0);
	vector<int> m2(size, 0);

	m1[0] = money[0];
	m1[1] = money[1];
	
	// money[0]와 money[size -1]은 같이 하면 안된다.
	// 마지막에 money[0]을 빼기위한 연산
	m2[1] = money[1];
	for(int i = 0; i < size; ++i) {
		if(i >= 2) {
			m1[i] = max(m1[i], m1[i - 2] + money[i]);
			m2[i] = max(m2[i], m2[i - 2] + money[i]);
		}
		if(i >= 3) {
			m1[i] = max(m1[i], m1[i - 3] + money[i]);
			m2[i] = max(m2[i], m2[i - 3] + money[i]);
		}
	}

	m1[size - 1] = m2[size - 1];

	for(int i : m1) cout << i << ' ';
	cout << endl;

	return *max_element(m1.begin(), m1.end());
}

int main() {
	vector<int> money =  { 1, 2, 3, 1};

	cout << solution(money) << endl;

	return 0;
}
