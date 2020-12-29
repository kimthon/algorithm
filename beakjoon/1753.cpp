#include<stdio.h>
#include<vector>
#include<climits>
#include<queue>

using namespace std;

class G {
	private:
		int pc; // 정점의 갯수
		int sp; // 시작하는 정점
		vector<vector<pair<int, int>>> line; //간선
		vector<int> wtp; // 정점까지 최단 거리

	public:
		G(int pc,int lc) : pc(pc), line(pc, vector<pair<int, int>>()), wtp(pc, INT_MAX) {
			int p1, p2, w;

			scanf("%d", &sp);
			wtp[--sp] = 0; // 시작하는 정점의 가중치는 0

			for(int i = 0; i < lc; ++i) {
				scanf("%d %d %d", &p1, &p2, &w);
				//first : 정점
				//second: 가중치
				line[p1 - 1].push_back(pair<int, int>(p2 - 1, w));
			}
		}

		void run() {
			priority_queue<pair<int, int>> pq;

			pq.push(pair<int, int>(0, sp));
			while(!pq.empty()) {
				int a = pq.top().second;
				int w = pq.top().first;
				pq.pop();

				if(wtp[a] < w) continue;

				for(auto i = line[a].begin(); i != line[a].end(); ++i) {
					int b = (*i).first;
					int pb = (*i).second;
					int pre = wtp[b];
					int now = wtp[a] + pb;

					if(now < pre) {
						wtp[b] = now;
						pq.push(pair<int, int>(-now, b));
					}
				}
			}
		}


		void print() {
			for(auto i = wtp.begin(); i != wtp.end(); ++i)
				if(*i == INT_MAX) printf("INF\n");
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
