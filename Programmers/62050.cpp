#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

#define ARROW_MAX 4
const int arrow_x[] = { 0, 1, 0, -1};
const int arrow_y[] = { 1, 0, -1, 0};

using xy = pair<int, int>;

vector<vector<int>> getMap(const vector<vector<int>> &land, const int &height) {
	vector<vector<int>> map(land.size(), vector<int>(land.size(), 0));

	int size = (int)land.size();
	int g_num = 0;
	for(int y = 0; y < size; ++y) {
		for(int x = 0; x < size; ++x) {
			if(map[y][x] != 0) continue;

			queue<xy> q;
			q.push({x, y});
			map[y][x] = ++g_num;
			while(!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for(int arrow = 0; arrow < ARROW_MAX; ++arrow) {
					int tmpX = x + arrow_x[arrow];
					int tmpY = y + arrow_y[arrow];

					if(tmpX >= size) continue;
					if(tmpY >= size) continue;
					if(tmpX < 0) continue;
					if(tmpY < 0) continue;

					// 이미 값을 바꾼 경우
					if(map[tmpY][tmpX] != 0) continue;

					int gap = abs(land[y][x] - land[tmpY][tmpX]);
					if(gap > height) continue;

					map[tmpY][tmpX] = g_num;
					q.push({tmpX, tmpY});
				}
			}
		}
	}
	return map;
}

int solution(vector<vector<int>> land, int height) {
	int cost = 0;
	vector<vector<int>> map = getMap(land, height);

	return cost;
}

int main() {
	vector<vector<int>> land = {{1, 4, 8, 10}, {5, 5, 5, 5}, {10, 10, 10, 10}, {10, 10, 10, 20}};
	int height = 3;

	cout << solution(land, height) << endl;

	return 0;
}
