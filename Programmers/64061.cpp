#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	vector<int> result;
	vector<vector<int>> s_board(board.size(), vector<int>());

	//낮은 곳 부터 채워넣기
	for(int y = board.size() - 1; y >= 0; --y) {
		for(int x = board[y].size() - 1; x >= 0; --x) {
			int num = board[y][x];
			if(num != 0) s_board[x].push_back(num);
		}
	}
	board.clear();
	
	int count = 0;
	for(auto i = moves.begin(); i != moves.end(); ++i) {
		int x = *i - 1;
		int num = s_board[x].back();
		if(num != 0) {
			s_board[x].pop_back();
			result.push_back(num);

			while(result.size() > 1 && (*result.rbegin() == *(result.rbegin() + 1))) {
				result.pop_back();
				result.pop_back();
				count += 2;
			}
		}
	}

	return count;
}

int main() {
	vector<vector<int>> board = {{0,0,0,0,0,}, {0,0,1,0,3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1}};
	vector<int> move = { 1, 5, 3, 5, 1, 2, 1, 4};

	cout << solution(board, move) << endl;
}
