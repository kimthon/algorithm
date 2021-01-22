#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	vector<int> memo;
	vector<bool> used(tickets.size(), false);

	auto cmp = [](const vector<string> &a, const vector<string> &b) {
		return a[1] < b[1];
	};

	sort(tickets.begin(), tickets.end(), cmp);

	int size = tickets.size();
	answer.push_back("ICN");
	bool pass = false;
	while(!answer.empty()) {

		int i;
		// pop 이후 이어갈 경우 그 다음부터 검색하면 됨
		// 아니라면 0부터 다시 검색
		if(!pass) i = 0;

		pass = true;
		for(; i < size; ++i) {
			if(used[i]) continue;
			if(tickets[i][0] == answer.back()) {
				answer.push_back(tickets[i][1]);

				cout << "push : " << tickets[i][1] << endl;

				memo.push_back(i);
				used[i] = true;
				pass = false;
				break;
			}
		}

		// 모든 티켓 사용시 탈출
		if(all_of(used.begin(), used.end(), [](bool b) { return b; } )) break;

		// 다음 목적지로 갈 수 없는 경우
		// 1. 방문 기록 삭제
		// 2. 다음 값 검색
		if(pass) {
			i = memo.back();
			used[i] = false;
			memo.pop_back();
			cout << "pop : " << answer.back() << endl;
			answer.pop_back();
			++i;
		}

		cout << endl;
	}

	return answer;
}


int main() {
	vector<vector<string>> tickets = {{"ICN", "AAA"}, {"ICN", "BBB"}, {"BBB", "ICN"}};

	for(string s : solution(tickets))
		cout << s << ',';
	cout << endl;

	return 0;
}
