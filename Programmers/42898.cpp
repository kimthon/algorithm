#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

int arrow_x[] = { 0, 1};
int arrow_y[] = { 1, 0};

// m : 가로 길이
// n : 세로 길이
int solution(int m, int n, vector<vector<int>> puddles) {
	// map[y][x]
	vector<vector<int>> map(n, vector<int>(m, 0));

	map[0][0] = 1;
	for(vector<int> puddle : puddles) map[puddle[1] - 1][puddle[0] - 1] = -1;

	queue<pair<int, int>> q;
	q.push({0, 0});
	while(!q.empty()) {
		pair<int ,int> xy = q.front();
		q.pop();

		for(int i = 0; i < 2; ++i) {
			int tmpx = xy.first + arrow_x[i];
			int tmpy = xy.second + arrow_y[i];

			if(tmpx >= m) continue;
			if(tmpy >= n) continue;

			// 물에 잠겨 있을 경우
			if(map[tmpy][tmpx] == -1) continue;

			if(map[tmpy][tmpx] == 0) q.push({tmpx, tmpy});
			map[tmpy][tmpx] += map[xy.second][xy.first];
			if(map[tmpy][tmpx] >= 1000000007) map[tmpy][tmpx] -= 1000000007;
		}
	}

	for(vector<int> line : map) {
		for(int i : line) cout << i << ' ';
		cout << endl;
	}

	return map[n - 1][m - 1];
}

int main() {
	int m = 1, n = 3;
	vector<vector<int>> puddles = {{1, 2}};

	cout << solution(m, n, puddles) << endl;

	return 0;
}
