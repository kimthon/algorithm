#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<map>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	queue<int> q;
	map<int, int> m;

	for(int i : priorities) {
		// map은 key 오름차순 정렬이기 때문에
		// 마이너스로 내림차순 정렬 유도
		q.push(-i);
		++m[-i];
	}

	auto max_p = m.begin();
	int &loc = location;
	while(!q.empty()) {
		int now_p = q.front();
		q.pop();

		// 지금 값이 최대 priority 일 경우
		if(now_p == max_p->first) {
			++answer;
			// 프린트 하는 값이 요청 문서라면 리턴
			if(loc == 0) return answer;
			// 현재 priority가 다 끝나면 다음으로 넘어감
			if(--max_p->second == 0) ++max_p;
		} else q.push(now_p);

		//요청 문서 이동
		if(--loc == -1) loc = q.size() - 1;
	}

	// 실패 했을 경우 리턴값
	return -1;
}

int main() {
	vector<int> priorities = { 1, 1, 9, 1, 1, 1};
	int location = 0;

	cout << solution(priorities, location) << endl;

	return 0;
}
