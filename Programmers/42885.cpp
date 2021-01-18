#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	sort(people.begin(), people.end(), greater<int>());

	int s = 0, e = people.size() - 1;
	while(s <= e) {
		if(people[s] + people[e] <= limit) --e;
		++answer; ++s;
	}

	return answer;
}

int main() {
	vector<int> people = { 70, 80, 50 };
	int limit = 100;

	cout << solution(people, limit) << endl;
	return 0;
}
