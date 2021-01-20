#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

// rout[i][0] : i번째 자동차가 고속도로에 진입한 지점
// rout[i][1] : i번째 자동차가 고속도로에서 나간 지점
int solution(vector<vector<int>> routes) {
	int answer = 0;

	auto cmp = [](const vector<int> &a, const vector<int> &b) {
		if(a[1] == b[1]) return a[0] > b[0];
		else return a[1] < b[1];
	};

	sort(routes.begin(), routes.end(), cmp);

	while(!routes.empty()) {
		int end = routes[0][1];
		++answer;
		cout << "camera point (" << end << ") : ";
		for(auto r = routes.begin(); r != routes.end();) {
			if((*r)[0] <= end) {
				cout << '(' << (*r)[0] << ',' << (*r)[1] << ')' << ',';
				r = routes.erase(r);
			}
			else ++r;
		}
		cout << endl;
	}

	return answer;
}

int main() {
	vector<vector<int>> routes = {{-20,15}, {-14,-5}, {-18,-13}, {-5,-3}};

	cout << solution(routes) << endl;

	return 0;
}
