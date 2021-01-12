#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool comp(pair<int,int> a, pair<int,int> b) {
	int ab = a.first*b.second + b.first;
	int ba = b.first*a.second + a.first;

	return ab < ba;
}

int get_pos(int a) {
	int count = 10;
	while((a = a/10) != 0) count *= 10;
	return count;
}

string solution(vector<int> numbers) {
	string	answer = "";
	vector<pair<int, int>> np;

	for(int n : numbers) np.push_back(pair<int,int>(n, get_pos(n)));

	sort(np.begin(),np.end(), comp);
	
	if(np[0].first == 0) return "0";
	for(auto n : np) answer += to_string(n.first);


	return answer;
}

int main() {
	vector<int> numbers = {1, 112};

	cout << solution(numbers) << endl;

	return 0;
}
