#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;
using xy = pair<int, int>;
using line = pair<xy, xy>;

int solution(vector<int> arrows) {
	int answer = 0;
	int x_arrow[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
	int y_arrow[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

	set<line> s;
	xy now = { 0, 0 };
	for(int arrow : arrows) {
		xy pre = now;
		now.first += x_arrow[arrow];	
		now.second += y_arrow[arrow];	

		if(now < pre) s.insert({now, pre});
		else s.insert({pre, now});
	}



	return answer;
}

int main() {
	vector<int> arrows;

	cout << solution(arrows) << endl;

	return 0;
}
