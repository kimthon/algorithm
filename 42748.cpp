#include<iostream>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> command) {
	vector<int> answer;

	for(vector<int> c : command) {
		--c[0];--c[1];--c[2];
		vector<int> tmp(c[1] - c[0] + 1);
		copy(array.begin() + c[0], array.begin() + c[1] + 1, tmp.begin()); 
		sort(tmp.begin(), tmp.end());
		answer.push_back(tmp[c[2]]);
	}

	return answer;
}

int main() {
	vector<int> array;
	vector<vector<int>> command;

	for(int i : solution(array, command))
		cout << i << ' ';
	cout << endl;
	
	return 0;
}
