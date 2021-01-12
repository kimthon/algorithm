#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

struct compare {
	bool operator()(pair<int, int> &a, pair<int, int> &b) {
		return a.second > b.second;
	}
};


int solution(vector<vector<int>> jobs) {
	int spended_time = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> not_yet;
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> wait;

	// first	: 들어온 시간
	// second	: 처리하는 데 걸리는 시간
	for(auto job : jobs) not_yet.push(pair<int, int>(job[0], job[1]));

	int time = 0;
	while(!not_yet.empty() || !wait.empty()) {
		if(wait.empty()) {
			auto j = not_yet.top();
			time = j.first;
			not_yet.pop();
			wait.push(j);
		}

		auto job = wait.top();
		wait.pop();
		time += job.second;
		spended_time += (time - job.first);

		cout << "들어온 시간 : " << job.first << endl;
		cout << "처리하는데 걸리는 시간 : " << job.second << endl;
		cout << "time : " << time << endl << endl;

		//처리하는 사이 들어온 일들을 wait로 이동
		while(!not_yet.empty() && not_yet.top().first <= time) {
			auto j = not_yet.top();
			not_yet.pop();
			wait.push(j);
		}
	}

	return spended_time / jobs.size();
}

int main() {
	vector<vector<int>> jobs = {{0, 3}, {1, 9}, {2, 6}};

	cout << solution(jobs) << endl;

	return 0;
}
