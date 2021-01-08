#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	int size = progresses.size();
	vector<int> answer;
	vector<int> days(size, 0);

	//몇일 있어야 끝 낼 수 있는지 계산
	int pre = 0;
	int count = 0;
	for(int i = 0; i < size; ++i) {
		int work = 100 - progresses[i];
		int day = work / speeds[i];
		if(work % speeds[i] != 0) ++day;

		// 제일 처음 들어 온 경우
		if(count == 0) {
			pre = day;
			++count;
		}
		else if(day <= pre) ++count;
		else {
			pre = day;
			answer.push_back(count);
			count = 1;
		}
	}

	// 마지막 값 넣어주기
	answer.push_back(count);

	return answer;
}

int main() {
	vector<int> progresses = { 93, 30, 55 };
	vector<int> speeds = {1, 30, 5};

	for(int i : solution(progresses, speeds))
			cout << i << ' ';
	cout << endl;
	
	return 0;
}
