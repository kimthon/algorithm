#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

// 바위 n개를 제거 한 뒤 지점 사이 최솟값 중 가장 큰 값을 리턴
// distance : 출발지점 에서 도착지점까지 거리
// rocks : 바위들의 위치를 담은 배열
// n : 제거할 바위의 수
int solution(int distance, vector<int> rocks, int n) {
	// 이분 탐색 기준을 최소 거리로 잡는다.
	int start = 0;
	int end = distance;

	sort(rocks.begin(), rocks.end());
	rocks.push_back(distance);

	int max_d = 0;
	while(start <= end) {
		int mid = (start + end)/2;
		int count = 0;
		int pre = 0;		
		int d;

		for(int rock : rocks) {
			d = rock - pre;
			if(d < mid) ++count;
			else pre = rock;
		}

		cout << "count : " << count << endl;
		cout << "start : " << start << endl;
		cout << "end   : " << end << endl;
		cout << "mid   : " << mid << endl << endl;

		// 제거해야하는 돌맹이 갯수가 조건
		if(count > n) end = mid - 1;
		else {
			max_d = max(max_d, mid);
			start = mid + 1;
		}
	}

	return max_d;
}

int main() {
	int distance = 16;
	vector<int> rocks = { 4, 8, 11};
	int n = 2;

	cout << solution(distance, rocks, n) << endl;

	return 0;
}
