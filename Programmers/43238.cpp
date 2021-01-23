#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

long long solution(int n, vector<int> times) {
	int size = times.size();

	sort(times.begin(), times.end());

	long long start = 0;
	long long end = times[size - 1]*n;
	long long mid = (start + end) / 2;

	while(start != end) {

		// 현재 시간에서 몇명이 가능한지 확인
		long count = 0;
		for(long long time : times) count += mid / time;

		if(count == n) break;
		else if(count < n) start = mid + 1;
		else end = mid;
		mid = (start + end) / 2;
	}

	// 나머지 값 빼기
	long long remain = 1000000000;
	for(int time : times) remain = min(remain, mid%time);

	cout << "remain : " << remain << endl;

	return mid - remain;
}

int main() {
	int n = 10;
	vector<int> times = { 3 };

	cout << solution(n, times) << endl;

	return 0;
}
