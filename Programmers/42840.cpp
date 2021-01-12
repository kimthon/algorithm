#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> v1 = { 1, 2, 3, 4, 5};
	vector<int> v2 = { 2, 1, 2, 3, 2, 4, 2, 5 };	
	vector<int> v3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

	vector<int> score(3);
	int size = answers.size();
	for(int i = 0; i < size; ++i) {
		int &a = answers[i];
		if(a == v1[i%v1.size()]) ++score[0];
		if(a == v2[i%v2.size()]) ++score[1];
		if(a == v3[i%v3.size()]) ++score[2];
	}

	vector<int> answer;
	int max = 0;
	for(int i = 0;i < 3; ++i) {
		if(max < score[i]) {
			answer.clear();
			max = score[i];
		}
		else if(max != score[i]) continue;

		// 같은 최대값을 가지는 경우
		answer.push_back(i + 1);
	}
	return answer;
}

int main() {
	vector<int> answer;

	for(int i : solution(answer))
			cout << i << ' ';
	cout << endl;

	return 0;
}
