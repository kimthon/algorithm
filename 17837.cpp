#include<iostream>

//#define DEBUG

using namespace std;

enum Color { WHITE = 0, RED = 1, BLUE = 2};
enum Arrow { RIGHT = 1, LEFT = 2, UP = 3, DOWN = 4};

class Toy {
	private:
		pair<int, int> xy;
		int power = 0; // how many move?
		Arrow arrow;
	public:
		Toy(int x, int y,int power, Arrow arrow) : xy(x,y),power(power), arrow(arrow) { }

		void Move() {
			switch (arrow) {
				case RIGHT:
					xy.first += power;
					break;
				case LEFT:
					xy.first -= power;
					break;
				case UP:
					xy.second -= power;
					break;
				case DOWN:
					xy.second += power;
					break;
			}

			if(xy.first > N) {
				xy.first = xy.first%N;
				if(arrow == UP) arrow = DOWN;
				else arrow = UP;
			}

			if(xy.second > N) {
				xy.second = xy.second%N;
				if(arrow == LEFT) arrow = RIGHT;
				else arrow = RIGHT;
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
