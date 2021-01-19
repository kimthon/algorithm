#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
	return a[2] < b[2];
}

// n : 총 섬의 갯수
// cost[n][0] ~ [1] : 연결 되는 두 섬
// cost[n][2] : 연결 비용
int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	set<int> *sets[n];
	for(int i = 0; i < n; ++i) {
		sets[i] = new set<int>();
		sets[i]->insert(i);
	}


	sort(costs.begin(), costs.end(), cmp);
	for(vector<int> cost : costs) {
		auto s1 = sets[cost[0]]->begin();
		auto s2 = sets[cost[1]]->begin();
		cout << cost[0] << '('<< *s1 <<')' <<':';
		cout << cost[1] << '(' << *s2 <<')';
		if(*s1 != *s2) {
			cout << " connected" << endl;
			int s = (*s1 > *s2) ? *s2 : *s1;
			int b = (*s1 > *s2) ? *s1 : *s2;

			// 최상위 노드만 누군지 알면 된다.
			// set은 오름차 순 정렬이기 때문에 s에 b를 삽입
			for(auto i = sets[b]->begin(); i != sets[b]->end(); ++i) {
				sets[s]->insert(*i);
				sets[*i]->insert(s);
			}

			answer += cost[2];
		}else cout << " disconnected" << endl;
	}

	return answer;
}

int main() {
	int n = 6;
	vector<vector<int>> costs = {{0, 1, 5}, {0, 3, 2}, {0, 4, 3}, {1, 4, 1}, {3, 4, 10}, {1, 2, 2}, {2, 5, 3}, {4, 5, 4}};

	cout << solution(n, costs) << endl;

	return 0;
}
