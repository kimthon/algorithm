#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

// n : 컴퓨터의 갯수
// comuters[i][j] : i와 j가 연결 되어 있는가?
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	vector<bool> visited(n, false);
	int &size = n;
	queue<int> *q = new queue<int>();
	for(int y = 0; y < size; ++y) {
		// 이미 네트워크에 속해 있다면 패스
		if(visited[y]) continue;
		q->push(y);

		while(!q->empty()) {
			int now = q->front();
			q->pop();
			visited[now] = true;

			for(int x = 0; x < size; ++x) {
				if(visited[x]) continue;
				if(computers[now][x] != 1) continue;
				q->push(x);
			}
		}
		++answer;
	}
	return answer;
}

int main() {
	int n = 3;
	vector<vector<int>> computers = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};


	cout << solution(n, computers) << endl;

	return 0;
}
