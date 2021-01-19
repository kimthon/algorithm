#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

// rout[i][0] : i번째 자동차가 고속도로에 진입한 지점
// rout[i][1] : i번째 자동차가 고속도로에서 나간 지점
int solution(vector<vector<int>> routes) {
	int answer = 0;

	auto cmp = [](const pair<int,int> &a, const pair<int,int> &b) {
		if(a.first == b.first) return a.second > b.second;
		return a.first < b.first;
	};

	set<pair<int,int>, decltype(cmp)> s(cmp);

	//시작 지점, 끝 지점 표시
	for(auto i : routes) {
		s.insert({i[0], i[1]});
		if(i[0] != i[1]) s.insert({i[1], i[0]});
	}

	while(!s.empty()) {
		multiset<pair<int,int>> save;
		multiset<pair<int,int>> tmp;

		for(const pair<int,int> &i : s) {
			// 시작 지점의 경우
			if(i.first <= i.second) tmp.insert( {i.first, i.second});

			//끝 지점의 경우
			if(i.second <= i.first){
				// 가장 큰 교차지점 저장
				if(save.size() < tmp.size()) save = tmp;
				tmp.erase({i.second, i.first});
			}
		}


		// 카메라로 찍힌 곳 제거
		++answer;
		for(const pair<int,int> &i : save) {
			s.erase(i);
			s.erase({i.second, i.first});
		}
	}

	return answer;
}

int main() {
	vector<vector<int>> routes = {{-20,15}, {-14,-5}, {-18,-13}, {-5,-3}};

	cout << solution(routes) << endl;

	return 0;
}
