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
	int mid = (start + end)/2;

	sort(rocks.begin(), rocks.end());

	while(start < end) {
		int count = 0;
		int pre = 0;		
		int min_d = distance;
		int d;

		for(int rock : rocks) {
			d = rock - pre;
			if(d < mid) ++count;
			else {
				pre = rock;
				min_d = min(min_d, d);
			}
		}

		// 마지막 distance는 제거할 수 없다.
		d = distance - pre;
		if(d >= mid) min_d = min(min_d, d);

		cout << "count : " << count << endl;
		cout << "start : " << start << endl;
		cout << "end   : " << end << endl;
		cout << "mid   : " << mid << endl << endl;

		// 제거해야하는 돌맹이 갯수가 조건
		if(count == n) return min_d;
		else if(count < n) start = mid + 1;
		else end = mid - 1;

		mid = (start + end)/2;
	}

	return mid;
}

int main() {
	int distance = 18;
	vector<int> rocks = { 2, 8, 9, 10, 11, 12, 13};
	int n = 6;

	cout << solution(distance, rocks, n) << endl;

	return 0;
}
