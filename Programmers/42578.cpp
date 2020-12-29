#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	unordered_map<string, int> um;

	for(vector<string> cloth : clothes) {
		if(um.find(cloth[1]) == um.end()) um.insert(pair<string, int>(cloth[1],1));
		else ++um[cloth[1]];
	}

	for(pair<string, int> cloth : um) answer *= (cloth.second + 1);

	return answer - 1;
}

int main() {
	vector<vector<string>> clothes = {{"yellow_hat", "headgear"},
		{"blue_sunglasses", "eyewaer"}, 
		{"green_turban", "headgear"}};

	cout << solution(clothes) << endl;

	return 0;
}
