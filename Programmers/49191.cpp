#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

// n : 선수의 수
// results[x][0] : 이긴 선수
// results[x][1] : 진 선수
int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	vector<vector<int>> up = vector<vector<int>>(n, vector<int>(n, -1));
	vector<vector<int>> down = vector<vector<int>>(n, vector<int>(n, -1));

	for(int i = 0; i < n; ++i) {
		up[i][i] = 0;
		down[i][i] = 0;
	}
	for(vector<int> r : results) {
		up[r[1] - 1][r[0] - 1] = 1;
		down[r[0] - 1][r[1] - 1] = 1;
	}

	for(int z = 0; z < n; ++z) {
		for(int y = 0; y < n; ++y) {
			if(z == y) continue;
			for(int x = 0; x < n; ++x) {
				if(z == x) continue;
				if(x == y) continue;

				// 연결할 수 없는 경우
				if(up[y][z] != -1 && up[z][x] != -1) up[y][x] = 1;
				if(down[y][z] != -1 && down[z][x] != -1) down[y][x] = 1;
			}
		}
	}


	for(int y = 0; y < n; ++y) {
		int count = 0;
		for(int x = 0; x < n; ++x) {
			if(up[y][x] == 1) ++count;
			if(down[y][x] == 1) ++count;
		}
		if(count == n - 1) ++answer;
	}

	return answer;
}

int main() {
	int n = 8;
	vector<vector<int>> results = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}};

	cout << solution(n, results) << endl;

	return 0;
}
