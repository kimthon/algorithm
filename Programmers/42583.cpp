#include<string>
#include<vector>
#include<iostream>
#include<queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	    int time = 0;
		int sum = 0;
		queue<pair<int, int>> q;

		for(int truck : truck_weights) {
			//while문을 지나가지 못할 경우 시간을 올려줌
			++time;

			// 1. 새로운 트럭이 들어 갈 수 있 을 때 까지 대기
			// 2. 다리가 꽉 차 있을 경우 대기
			bool weight_over = (!q.empty() && sum + truck > weight);
			bool fulled = (int)q.size() == bridge_length;
			while(weight_over || fulled) {
				time = bridge_length + q.front().second;

				cout << "시간 : " << time << endl;
				cout << "트럭 : " << q.front().first << " 빠져나감(" << q.front().second << ')' << endl;

				sum -= q.front().first;
				q.pop();

				//다시 값 비교
				//fulled는 이미 하나 이상 빠져나갔으니 false
				weight_over = (!q.empty() && sum + truck > weight);
				fulled = false;

				if(weight_over) cout << endl;
			}

			// 새로운 트럭 추가
			sum += truck;
			cout << "시간 : " << time << endl;
			cout << "트럭 : " << truck << " 추가됨" << endl;
			q.push(pair<int,int>(truck, time));

			cout << "총 weight : " << sum << endl << endl;
		}

		//마지막 차량이 넘어간 시간 더해주기
		time += bridge_length;

		cout << endl;

		return time;
}

int main() {
	int length = 5;
	int weight = 5;
	vector<int> tweights = {2, 2, 2, 2, 1, 1, 1, 1};

	cout << solution(length, weight, tweights) << endl;

	return 0;
}
