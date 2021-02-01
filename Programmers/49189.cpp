#include<iostream>
#include<string>
#include<vector>
#include<climits>
#include<queue>
#include<algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
	vector<int> dept(n, INT_MAX);
	vector<vector<int>> line(n, vector<int>());
	queue<int> q;

	dept[0] = 0;

	for(vector<int> e : edge) {
		line[e[0] - 1].push_back(e[1] - 1);
		line[e[1] - 1].push_back(e[0] - 1);
	}

	q.push(0);
	while(!q.empty()) {
		int now = q.front();
		int next_dept = dept[now] + 1;
		q.pop();

		for(int p : line[now]) {
			if(dept[p] <= next_dept) continue;
			dept[p] = next_dept;
			q.push(p);
		}
	}

	int count = 1;
	sort(dept.begin(), dept.end(), greater<int>());
	auto i = dept.begin();
	while(*i == INT_MAX) ++i;
	while((i + 1) != dept.end()) {
		if(*i != *(i + 1)) break;
		++i;
		++count;
	}

	return count;
}

int main() {
	int n = 6;
	vector<vector<int>> edge = {{3, 6}, {4, 3} ,{3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};

	cout << solution(n, edge) << endl;
}
