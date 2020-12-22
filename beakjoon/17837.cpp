#include<iostream>

//#define DEBUG

using namespace std;

enum Color { WHITE = 0, RED = 1, BLUE = 2};
enum Arrow { RIGHT = 1, LEFT = 2, UP = 3, DOWN = 4};

class Toy {
	private:
		pair<int, int> xy;
		Arrow arrow;
	public:
		Toy(int x, int y, Arrow arrow) : xy(x,y), arrow(arrow) {

		}

		pair<int, int> WillMove() {
			pair<int, int> tmp = xy;
			switch (arrow) {
				case Arrow.RIGHT:
					tmp.first += 1;
					break;
				case Arrow.LEFT:
					tmp.first -= 1;
					break;
				case Arrow.UP:
					tmp.second -= 1;
					break;
				case Arrow.DOWN:
					tmp.second += 1;
					break;
			}
		}
};

class Board {
	private:
		int size = 0;
		int** c_board = NULL;

		void InitBoard(int**& board) {
			DelBoard(board);

			board = new int*[size];
			for(int i = 0; i < size; ++i)
				board[i] = new int[size];
		}
		
		void SetBoard(int** board) {
			for(int i = 0; i < size; ++i)
				for(int j = 0; j < size; ++j)
					cin >> board[i][j];
		}

		void DelBoard(int** board) {
			if(board == NULL) return;
			for(int i = 0; i < size; ++i)
				delete board[i];
			delete board;
			board = NULL;
		}

	public:
		Board(int size) : size(size) {
			InitBoard(c_board);
			SetBoard(c_board);
		}

		~Board() {
			DelBoard(c_board);
		}
};

int main() {

	return 0;
}
