#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

static vector<bool> prime = { false, false, true };

bool isPrime(int num) {
	if(num < (int)prime.size()) return prime[num];

	// 범위 안에 없다면 재할당
	int presize = prime.size();
	prime.resize(num + 1, true);

	int max = (int)sqrt(num);
	for(int i = 2; i <= max; ++i) {
		// 소수가 아닌 값은 패스
		if(!prime[i]) continue;

		// 이전 체크한 부분은 패스
		for(int n = presize + i - presize%i; n <= num; n += i)
		   	prime[n] = false;
	}

	return prime[num];
}

int solution(string numbers) {
	int answer = 0;

	int size = numbers.size();
	// 총 몇자리 수를 만들 것인가
	for(int digit = size;0 < digit; --digit) {

	}

	return answer;
}

int main() {
	string nums;
	cin >> nums;

	cout << solution(nums) << endl;


	return 0;
}
