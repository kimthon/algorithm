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
	for(int i =0; i < size; ++i) {
		int &price = prices[i];
		//가격 하락시
		if(s.top().second > price) {
			while(s.top().second > price) {
				auto tmp = s.top();
				s.pop();
				answer[tmp.first] = s.size();
			}
		}else { //가격 상승||같을 시
			s.push(pair<int, int>(i, price));
		}
	}

	// 스택에 남은 값 비워내기
	while(!s.empty()) {
		auto tmp = s.top();
		s.pop();
		answer[tmp.first] = s.size();
	}

	return answer;
}

int main() {
	vector<int> prices = { 1, 2, 3, 2, 3 };

	for(int i : solution(prices)) cout << i << endl;

	return 0;
}
