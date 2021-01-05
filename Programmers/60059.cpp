#include<string>
#include<vector>

using namespace std;


bool unlocked(vector<vector<int>>& lock, int& size) {
	for(int y = 0; y < size; ++y)
		for(int x = 0; x < size; ++x)
			if(lock[y][x] != 1) return false;
	return true;
}

vector<vector<int>> adding(int& base_x, int& base_y, vector<vector<int>>& key, vector<vector<int>>& lock) {
	vector<vector<int>> tmp;

	int key_size = key.size();

	for(int x = 0; x < key_size; ++x)
		for(int y = 0; y < key_size; ++y)
			//만약 두 값이 일치하는 경우
			// 1. 둘 다 1일 경우 : 충돌
			// 2. 둘 다 0일 경우 : 키가 맞지 않음
			if(key[y][x] != lock[y][x]) {

			}
			else {
				tmp.clear();
				return tmp;
			}

	return tmp;
}

bool IsInRange(int& x, int& y, int& lock_size, int& key_size) {
	//좌측과 상단의 패딩 영역
	if(x < key_size - 1) return false;
	if(y < key_size - 1) return false;

	//우측과 하단의 패딩 영역
	if(x >= lock_size + key_size - 1) return false;
	if(y >= lock_size + key_size - 1) return false;

	return true;
}

bool solution(vector<vector<int>>key, vector<vector<int>> lock) {
	int size = lock.size();

	vector<vector<int>> tmp;
	for(int base_y = 0; base_y < size; ++base_y)
		for(int base_x = 0; base_x < size; ++base_x) {

		}

	return false;
}

int main() {
	return 0;
}
