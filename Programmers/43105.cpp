#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
	vector<vector<int>> memo;
	for(int i = 0; i < (int)triangle.size(); ++i)
		memo.push_back(vector<int>(i + 1, 0));

	int size = triangle.size() - 1;
	memo[0][0] = triangle[0][0];
	for(int l = 0; l < size; ++l) {
		for(int i = 0; i <= l; ++i) {
			memo[l + 1][i] = max(memo[l + 1][i], memo[l][i] + triangle[l + 1][i]);
			memo[l + 1][i + 1] = max(memo[l + 1][i + 1], memo[l][i] + triangle[l + 1][i + 1]);
		}
	}

	for(vector<int> line : triangle) {
		for(int i : line) cout << i << ' ';
		cout << endl;
	}

	cout << endl;
	for(vector<int> line : memo) {
		for(int i : line) cout << i << ' ';
		cout << endl;
	}

	return *max_element(memo[size].begin(), memo[size].end());
}

int main() {
	vector<vector<int>> triangle = { {7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};

	cout << solution(triangle) << endl;

	return 0;
}
