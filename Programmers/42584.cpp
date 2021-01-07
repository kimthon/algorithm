#include<string>
#include<vector>
#include<stack>
#include<iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size(), 0);
	//first : 번호
	//second : 가격
	stack<pair<int, int>> s;

	int size = prices.size();
	for(int i = 0; i < size; ++i) {
		int &price = prices[i];

		//가격 하락시
		while(!s.empty() && s.top().second > price) {
			auto tmp = s.top();
			s.pop();
			answer[tmp.first] = i - tmp.first;
		}

		s.push(pair<int, int>(i, price));
	}

	// 스택에 남은 값 비워내기
	while(!s.empty()) {
		auto tmp = s.top();
		s.pop();
		answer[tmp.first] = size - tmp.first - 1;
	}

	return answer;
}

int main() {
	vector<int> prices = { 1, 2, 3, 2, 3};

	for(int i : solution(prices)) cout << i << ' ';
	cout << endl;

	return 0;
}
