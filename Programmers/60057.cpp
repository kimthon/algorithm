#include<iostream>
#include<vector>
#include<string>

using namespace std;

int solution(string s) {
	int answer = s.length();
	int max = s.length()/2;

	for(int i = 1; i <= max; ++i) {
		int size = s.length();
		string tmp = "";
		string str1 = s.substr(0, i);
		int count = 1;
		for(int j = i; j <= size; j += i) {
			string str2 = s.substr(j, i);
			if(str1.compare(str2) == 0) {
				++count;
			} else {
				if(count != 1) {
					tmp += to_string(count);
					count = 1;
				}
				tmp += str1;
				str1 = str2;
			}
		}

		if(count != 1) tmp += to_string(count) + str1;

		int num = tmp.length() + size%i;
		if(num < answer) answer = num;
	}

	return answer;
}

int main() {
	string s;
	cin >> s;

	cout << solution(s) << endl;
}
