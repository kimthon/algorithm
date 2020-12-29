#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

string solution(vector<string> partic, vector<string> comple) {
	string answer = "";

	unordered_map<string, int> um;


	for(auto i = comple.begin(); i != comple.end(); ++i) {
		string &s = *i;
		auto f = um.find(s);
		if(f == um.end()) um.insert(pair<string, int>(s, 1));
		else ++(f->second);
	}

	for(auto i = partic.begin(); i != partic.end(); ++i) {
		string &s = *i;
		auto f = um.find(s);
		if(f == um.end()) return s;
		else if((f->second)-- == 0) return s;
	}

	return answer;
}

int main() {
	vector<string> partic = { "leo", "kiki", "eden" };
	vector<string> comple = { "eden", "kiki" };

	cout << solution(partic, comple) << endl;
	return 0;
}
