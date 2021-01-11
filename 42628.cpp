#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	multiset<int> ms;

	for(string op : operations) {
		int num = stoi(op.substr(2, op.length() - 2));

		if(op[0] == 'I') ms.insert(num); 
		else if(ms.empty()) continue;
		else if(num == -1) ms.erase(ms.begin());
		else ms.erase(--ms.end());
	}

	if(ms.empty()) {
		answer.push_back(0);
		answer.push_back(0);
	}else {
		answer.push_back(*ms.rbegin());
		answer.push_back(*ms.begin());
	}
	return answer;
}

int main() {
	vector<string> operations = {"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"};
	vector<int> answer = solution(operations);

	cout << "최대 값 : " << answer[0] << endl;
	cout << "최소 값 : " << answer[1] << endl;

	return 0;
}
