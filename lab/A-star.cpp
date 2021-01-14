#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

const static vector<pair<int, int>> arrows ={{-1, 1},	{0, 1},	{1, 1},
											{-1, 0},			{1, 0},
											{-1, -1},	{0, -1},{1, -1}};

class Map {
	private:
		const static int wall_v = -1;
		const static int path_v = -2;

		vector<vector<int>> m;
		pair<int, int> start;
		pair<int, int> end;

		void SetPoint(int x, int y, pair<int, int>& val) { 
			if(x < 0 || x >= (int)m.size()) return;
			if(y < 0 || y >= (int)m.size()) return;

			val = {x, y};
		}
	public:
		Map(int n) : m(n, vector<int>(n, 0)), start(0, 0), end(n-1, n-1) { }

		void SetWall(int x, int y) { m[y][x] = wall_v; }
		
		void SetStart(int x, int y) { SetPoint(x, y, start);	}
		void SetEnd(int x, int y) { SetPoint(x, y, end);	}


		void Run() {
			using xy = pair<int,int>;
			priority_queue<pair<int, xy>,vector<pair<int, xy>>, greater<pair<int, xy>>> pq;
			pq.push({0, start});

			while(!pq.empty()) {
				xy now = pq.top().second;
				pq.pop();

				//목적지 도착시
				if(now.first == end.first && now.second == end.second) {
					Print();
					return;
				}

				for(pair<int, int> arrow : arrows) {
					int x = now.first + arrow.first;
					int y = now.second + arrow.second;

					if(x < 0 || x >= (int)m.size()) continue;
					if(y < 0 || y >= (int)m.size()) continue;
					if(m[y][x] == wall_v) continue;

					//새로 찾은 값이 훨씬 빠른 경로라면
					if(m[y][x] == 0 || m[now.second][now.first] + 1 < m[y][x]) {
						//g(n) : 이동하는데 걸린 시간
						m[y][x] = m[now.second][now.first] + 1;

						//h(n) : 앞으로 예상 시간
						int max_x = (x > end.first) ? x - end.first : end.first - x;
						int max_y = (y > end.second) ? y - end.second : end.second - y;
						int h = max(max_x, max_y);

						pq.push({h + m[y][x], {x, y}});
					}
				}
			}
		}

		void Print() {
			for(vector<int>y : m) {
				for(int x : y) {
					if(x == path_v) cout << '*' << '\t';
					else cout << x << '\t';
				}
				cout << endl;
			}
		}
};

int main() {
	int n;
	cout << "맵의 크기를 입력해주세요 : ";
	cin >> n;

	Map m(n);
	cout << "벽의 개수" << endl;
	cin >> n;

	for(int i = 0; i < n; ++i) {
		int x, y;
		cout << i << "번째 벽의 좌표 :";
		cin >> x >> y;
		m.SetWall(x, y);
	}

	m.Run();

	return 0;
}
