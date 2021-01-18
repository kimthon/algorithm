#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n - lost.size();

	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());

	auto r = reserve.begin();
	for(int &l : lost) {
		if(l == INT_MAX) continue;
		for(;r != reserve.end();++r) {
			if(l == *r) {
				cout << "l : " << l << ", r : " << *r << endl;
				l = INT_MAX;
				*r = INT_MAX;
				++answer;
				++r;
				break;
			}else if(l < *r) break;
		}
	}


	r = reserve.begin();
	for(int &l : lost) {
		if(l == INT_MAX) continue;
		for(;r != reserve.end();++r) {
			if(*r == INT_MAX) continue;
			else if(*r + 1 == l || *r - 1 == l) {
				cout << "l : " << l << ", r : " << *r << endl;
				++answer;
				++r;
				break;
			}else if( l < *r - 1) break;
		}
	}

	return answer;
}

int main() {
	int n = 5;
	vector<int> lost = { 1, 2, 4, 5 };
	vector<int> reserve = { 2, 3, 4} ;

	cout << solution(n, lost, reserve) << endl;

	return 0;
}
