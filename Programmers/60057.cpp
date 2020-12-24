#include<iostream>
#include<vector>
#include<string>

using namespace std;

int solution(string s) {
	int answer = s.length();
	int max = s.length()/2;

	for(int i = 1; i <= max; ++i) {
		int size = s.length();
		int count = 1;
		int num = size % i;
		string str1 = s.substr(0, i);

		for(int j = i; j <= size; j += i) {
			string str2 = s.substr(j, i);
			if(str1.compare(str2) == 0) {
				++count;
			} else {
				if(count != 1) {
					do {
						++num;
					}while((count = count / 10) > 0);
					count = 1;
				}
				num += i;
				str1 = str2;
			}
		}

		if(count != 1) {
			do {
				++num;
			}while((count = count / 10) > 0);
			num += i;
		}
		if(num < answer) answer = num;
	}
	return answer;
}

int main() {
	string s;
	cin >> s;

	cout << solution(s) << endl;
}
