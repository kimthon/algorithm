#include<iostream>
#include<vector>
#include<climits>
#include<queue>

using namespace std;

class G {
	private:
		int pc; // 정점의 갯수
		int sp; // 시작하는 정점
		vector<vector<pair<int, int>>> line; //간선
		vector<bool> visited; //방문 여부
		vector<int> wtp; // 정점까지 최단 거리

		bool all_visited() {
			for(auto i = visited.begin(); i != visited.end(); ++i)
				if(!(*i)) return false;
			return true;
		}

		int find_min_wtp() {
			int v = 0;
			int w = INT_MAX;

			for(int i = 0; i < pc; ++i) {
				if(visited[i]) continue;
				if(w < wtp[i]) continue;

				v = i;
				w = wtp[i];
			}

			return v;
		}

	public:
		G(int pc,int lc) : pc(pc), line(pc, vector<pair<int, int>>()), wtp(pc, INT_MAX) {
			int p1, p2, w;

			cin >> sp;
			wtp[--sp] = 0; // 시작하는 정점의 가중치는 0

			for(int i = 0; i < lc; ++i) {
				cin >> p1 >> p2 >> w;
				//first : 정점
				//second: 가중치
				line[p1 - 1].push_back(pair<int, int>(p2 - 1, w));
			}
		}

		void run() {
			visited = vector<bool>(pc, false);
			
			while(!all_visited()) {
				int a = find_min_wtp();
				for(auto i = line[a].begin(); i != line[a].end(); ++i) {
					int b = (*i).first;
					int pb = (*i).second;
					if(!visited[b]) wtp[b] = min(wtp[b], wtp[a] + pb);
				}
				visited[a] = true;
			}
		}


		void print() {
			for(auto i = wtp.begin(); i != wtp.end(); ++i)
				if(*i == INT_MAX) cout << "INF" << endl;
				else cout << *i << endl;
		}
};

int main() {
	int pc, lc;

	cin >> pc >> lc;

	G g(pc, lc);

	g.run();
	g.print();
}
