#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

bool canChange(const string &a, const string &b) {
	bool check = false;
	int size = a.size();
	for(int i = 0; i < size; ++i) {
		if(a[i] != b[i]) {
			// 두개 이상 다르면 변환 불가
			if(check) return false;
			else check = true;
		}
	}
	return true;
}

bool IsTargetThere(const string &target, vector<string> &words) {
	for(const string &word : words) if(word == target) return true;
	return false;
}

int solution(string begin, string target, vector<string> words) {
	vector<int> dp(words.size(), INT_MAX);
	if(!IsTargetThere(target, words)) return 0;
	
	queue<int> q;
	int size = words.size();
	for(int i = 0; i < size; ++i) {
		if(!canChange(begin, words[i])) continue;
		cout << i << endl;
		dp[i] = 1;
		q.push(i);
	}

	while(!q.empty()) {
		int now = q.front();
		q.pop();
		for(int j = 0; j < size; ++j) {
			if(dp[j] < dp[now] + 1) continue;
			if(!canChange(words[now], words[j])) continue;
			cout << "dp[" << j << "] : " << dp[j] << ", dp[" << now << "] : " << dp[now] << endl;
			dp[j] = dp[now] + 1;
			cout << "dp[" << j << "] : " << dp[j] << ", dp[" << now << "] : " << dp[now] << endl;
			q.push(j);
		}
	}

	int answer = INT_MAX;
	for(int i = 0; i < size; ++i)
		if(words[i] == target) answer = min(answer, dp[i]);

	if(answer == INT_MAX) return 0;
	else return answer;
}

int main() {
	string begin = "hit";
	string target = "cog";
	vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};

	cout << solution(begin,target, words) << endl;

	return 0;
}
