#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	sort(citations.begin(), citations.end(), greater<int>());
	int size = citations.size();


	for(int i : citations) cout << i << ' ';
	cout << endl;
	
	for(int i = 0; i < size; ++i) {
		int &c = citations[i];

		// c : 현재 논문이 인용된 갯수
		// i : c번 이상 인용된 논문의 갯수
		if(c <= i + 1) return max(c, answer);
		else answer = i+1;
	}

	return answer;
}

int main() {
	vector<int> citations = {12,11,10,9,8,1};

	cout << solution(citations) << endl;

	return 0;
}
