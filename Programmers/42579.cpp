#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

bool comp(pair<int,int> a, pair<int, int> b) {
	return (a.first > b.first);
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	vector<vector<pair<int, int>>> gen_sorted;
	vector<pair<int, int>> play_sorted;
	unordered_map<string, int> GTN;

	// ++연산을 위해 -1로 설정
	int g_size = -1;
	int size = genres.size();

	for(int i = 0; i < size; ++i) {
		string &gen = genres[i];

		auto gn = GTN.find(gen);
		int num;

		if(gn == GTN.end()) {
			GTN[gen] = ++g_size;
			num = g_size;

			//새로 항목 생성 후 넣기
			gen_sorted.push_back(vector<pair<int, int>>());
			play_sorted.push_back(pair<int, int>(0, g_size));
		}else { num = gn->second; }

		gen_sorted[num].push_back(pair<int, int>(plays[i], i));
		play_sorted[num].first += plays[i];
	}

	//크기 별로 정렬
	sort(play_sorted.begin(), play_sorted.end(), comp);
	for(auto i = gen_sorted.begin(); i != gen_sorted.end(); ++i) sort(i->begin(), i->end(), comp);	

	//가장 많이 팔린 음악
	for(auto gen : play_sorted) {
		int &num = gen.second;
		//가장 많이 팔린 노래
		int count = 0;
		for(auto i : gen_sorted[num]) {
			answer.push_back(i.second);
			if(++count == 2) break;
		}
	}

	
	return answer;
}

int main() {
	vector<string> genres = {"classic", "pop", "classic","classic", "pop"};
	vector<int> plays = { 500, 600, 150, 800, 2500};


	for(int i : solution(genres, plays))
		cout << i << endl;

	return 0;
}
