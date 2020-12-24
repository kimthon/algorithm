#include<iostream>
#include<vector>
#include<string>

using namespace std;

string solution(string p) {
	string u = "", v = "";
	
	int size = p.length();
	int count = 0;
	bool bal = true;

	//1번 과정
	if(p.empty()) return "";
	//2번 과정
	for(int i = 0; i < size; ++i) {
		if(p[i] == '(') ++count;
		else --count;

		if(count < 0) bal = false;

		//균형잡힌 괄호 문자열
		if(count == 0) {
			u = p.substr(0, i + 1);
			if(size != i + 1) v = p.substr(i + 1);
			break;
		}
	}

	//3번 과정
	if(bal) {
		v = solution(v);
		return u + v;
	} else { //4번 과정
		v = "(" + solution(v) + ")";
		u = u.substr(1, u.length() -2);
		for(int i = u.size(); i >= 0; --i) {
			if(u[i] == '(') u[i] = ')';
			else u[i] = '(';
		}

		return v + u;
	}
}

int main() {
	string s;
	cin >> s;

	cout << solution(s) << endl;

	return 0;
}
