#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

int solution(vector<int> numbers, int target) {
	int answer = 0;
	queue<int> *q = new queue<int>();
	queue<int> *nq = new queue<int>();

	q->push(0);	
	for(int num : numbers) {
		swap(q, nq);
		while(!nq->empty()) {
			int i = nq->front();
			nq->pop();

			q->push(i + num);
			q->push(i - num);
		}
	}

	for(;!q->empty();q->pop()) if(q->front() == target) ++answer;

	delete q;
	delete nq;
	
	return answer;
}

int main() {
	vector<int> numbers = {1, 1, 1, 1, 1};
	int target = 3;

	cout << solution(numbers, target) << endl;
	
	return 0;
}
