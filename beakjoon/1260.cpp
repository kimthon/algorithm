#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

class G {
	private:
		int pc; // 정점의 개수
		int sp; // 탐색을 시작할 정점
		vector<vector<int>> line;

	public:
		G(int pc, int lc, int sp):pc(pc), sp(sp - 1), line(pc, vector<int>()) {
			int p1, p2;
			for(int i = 0; i < lc; ++i) {
				cin >> p1 >> p2;
				line[p1 - 1].push_back(p2 - 1);
				line[p2 - 1].push_back(p1 - 1);
			}

			for(int i = 0; i < pc; ++i)
				sort(line[i].begin(), line[i].end());
		}

		void DFS() {
			vector<bool> visited(pc, false);
			visited[sp] = true;

			stack<int> s;
			s.push(sp);

			cout << sp + 1 << ' ';
			while(!s.empty()) {
				int p = s.top();
				bool f = true;

				for(auto i = line[p].begin(); i != line[p].end(); ++i) {
					if(!visited[*i]) {
						cout << *i + 1 << ' ';
						visited[*i] = true;
						f = false;
						s.push(*i);
						break;
					}
				}

				//만약 다른 정점을 모두 방문했다면
				//정점을 스택에서 제거한다.
				if(f) s.pop();
			}
			cout << endl;

		}

		void BFS() {
			vector<bool> visited(pc, false);
			visited[sp] = true;

			queue<int> q;
			q.push(sp);

			cout << sp + 1 << ' ';
			while(!q.empty()) {
				int p = q.front();
				q.pop();

				for(auto i = line[p].begin(); i != line[p].end(); ++i) {
					if(!visited[*i]) {
						cout << *i + 1<< ' ';
						visited[*i] = true;
						q.push(*i);
					}
				}
			}

			cout << endl;
		}
};

int main() {
	int pc, sp, lc;

	cin >> pc >> lc >> sp;
	G g(pc, lc, sp);

	g.DFS();
	g.BFS();

	return 0;
}
