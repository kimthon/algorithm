#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> carpet(2, 3);
	
	int sum = brown + yellow;
	for(int w = 3;;++w) {
		for(int h = 3; h <= w; ++h) {
			if(w*h == sum && (w - 2)*(h - 2) == yellow) {
				carpet[0] = w;
				carpet[1] = h;
				return carpet;
			}
		}
	}

	return carpet;
}

int main() {
	int brown;
	int yellow;

	cin >> brown >> yellow;

	vector<int> carpet = solution(brown, yellow);
	cout << "가로 : " << carpet[0] << endl;
	cout << "세로 : " << carpet[1] << endl;

	return 0;
}
