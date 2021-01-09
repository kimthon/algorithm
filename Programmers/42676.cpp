#include<iostream>
#include<vector>
#include<set>

using namespace std;

int solution(vector<int> scoville, int k) {
	int count = 0;
	multiset<int> s;

	for(int i : scoville) s.insert(i);

	//첫 값 검사
	if(*s.begin() >= k) return count;
	while(s.size() > 1) {
		auto first = s.begin();
		auto second = ++s.begin();


		// 새로운 스코빌 생성 및 기존 스코빌 제거
		int new_k = *first + 2*(*(second++));
		s.erase(first, second);
		s.insert(new_k);

		++count;

		// 제일 첫 값이 k 보다 크면 리턴
		if(*s.begin() >= k) return count;
	}

	return -1;
}

int main() {
	vector<int> scoville = {1, 2, 3, 9, 10, 12};
	int k = 7;

	cout << solution(scoville, k) << endl;

	return 0;
}
