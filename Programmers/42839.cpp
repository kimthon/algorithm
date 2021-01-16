#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>


using namespace std;

static vector<bool> prime = { false, false, true };

bool isPrime(int num) {
	if(num < (int)prime.size()) return prime[num];

	// 범위 안에 없다면 재할당
	int presize = prime.size() - 1;
	prime.resize(num + 1, true);

	for(int i = 2; i*i <= num; ++i) {
		// 소수가 아닌 값은 패스
		if(!prime[i]) continue;

		int n = (i < presize) ? presize + i - presize%i : 2*i;
		for(; n <= num; n += i) prime[n] = false;
	}

	return prime[num];
}

int solution(string numbers) {
	int answer = 0;
	set<int, greater<int>> s;
	

	int size = numbers.size();
	// 총 몇자리 수를 만들 것인가
	sort(numbers.begin(), numbers.end());
	for(int digit = size;0 < digit; --digit) {
		vector<bool> select;
		for(int i = digit; i < size; ++i) select.push_back(false);
		for(int i = 0; i < digit; ++i) select.push_back(true);

		do {
			string str;
			for(int i = 0; i < size; ++i) if(select[i]) str += numbers[i];
			
			do {
				s.insert(stoi(str));
			}while(next_permutation(str.begin(), str.end()));
		}while(next_permutation(select.begin(), select.end()));
	}

	for(int i : s) {
		if(isPrime(i)) ++answer;
	}

	return answer;
}

int main() {
	string nums;
	cin >> nums;

	cout << solution(nums) << endl;

	return 0;
}
