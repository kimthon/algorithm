#include<iostream>
#include<climits>
#include<algorithm>
#include<cstring>

#define DEBUG

using namespace std;

class Solution {
	private:
		int** array = NULL;
		int** area = NULL;
#ifdef DEBUG
		int** tmp = NULL;
#endif

		int size = 0;

		int min_value = INT_MAX;

		void InitArray(int**& array) {
			if(array != NULL) DelArray(array);

			array = new int*[size];
			for(int i = 0; i < size; ++i)
				array[i] = new int[size];
		}

		int SumResult() {
			int area_sum[6] = {0, 0, 0, 0, 0, 0} ;
			for(int i = 0; i < size; ++i)
				for(int j = 0; j < size; ++j) {
					int area_num = area[i][j];
					int human = array[i][j];
					area_sum[area_num] += human;
				}

			int min = *min_element(area_sum + 1, area_sum + 6);
			int max = *max_element(area_sum + 1, area_sum + 6);

			return (max - min);
		}

		void SetArray(int** array) {
			for(int i = 0; i < size; ++i)
				for(int j = 0; j < size; ++j)
					cin >> array[i][j];
		}

		void SetArea(int x, int y, int d1, int d2) {
			//범위 외의 값으로 초기화
			for(int i = 0; i < size; ++i)
				memset(area[i], 0, sizeof(int)*size);

			//테두리 씌우기
			for(int i = 0; i <= d1; ++i) {
				area[x + i][y - i] = 5;
				area[x + d2 + i][y + d2 - i] = 5;
			}

			for(int i = 0; i <= d2; ++i) {
				area[x + i][y + i] = 5;
				area[x + d1 + i][y - d1 + i] = 5;
			}

			//테두리 채우기
			for(int i = 0; i < d1; ++i)
				for(int j = 1; ; ++j)
				{
					int& tmp = area[x + i + j][y - i];
					if(tmp == 5) break;
					tmp = 5;
				}

			//중간은 겹치기 때문에 패스
			for(int i = 1; i < d2; ++i)
				for(int j = 1; ; ++j)
				{
					int& tmp = area[x + i + j][y + i];
					if(tmp == 5) break;
					tmp = 5;
				}

			// 1 <= r < x + d1, 1 <= c <= y
			SetExtraArea(0, x + d1, 0, y + 1, 1);
			// 1 <= r <= x + d2, y < c <= N
			SetExtraArea(0, x + d2 + 1, y + 1, size, 2);
			// x + d1 <= r <= N, 1 <= c < y - d1 + d2
			SetExtraArea(x + d1, size, 0, y - d1 + d2 , 3);
			// x + d2 < r < N, y - d1 + d2 <= c <= N
			SetExtraArea(x + d2 + 1, size, y - d1 + d2, size, 4);

		}

		void DelArray(int** array) {
			for(int i = 0; i < size; ++i)
				delete array[i];
			delete array;
			array = NULL;
		}

		void SetExtraArea(int x1, int x2, int y1, int y2, int num) {
			for(int i = x1; i < x2; ++i)
				for(int j = y1; j < y2; ++j) 
					if(area[i][j] != 5) area[i][j] = num;
		}

	public:
		Solution(int size) {
			this->size = size;

			InitArray(array);
			InitArray(area);
#ifdef DEBUG
			InitArray(tmp);
#endif

			SetArray(array);
		}


		void Run() {
			// Set 파라미터 생성
			// 4중 for문은 문제가 있다 어떻게 수정하면 좋은가....
			for(int x = 1; x < size - 1; ++x)
				for(int y = 1; y < size - 1; ++y)
					for(int d1 = 1; 0 <= y - d1; ++d1)
						for(int d2 = 1; (x + d1 + d2 < size)&&(y + d2 < size); d2++) {
							SetArea(x, y, d1, d2);
							int num = SumResult();
							if(num < min_value) {
								min_value = num;
								for(int i = 0; i < size; ++ i)
									memcpy(tmp[i], area[i], sizeof(int)*size);
							}
						}


		}
		int Result() { return min_value; }

#ifdef DEBUG
		void Print() {
			for(int i = 0; i < size; ++i)
			{
				for(int j = 0; j < size; ++j)
					cout << tmp[i][j] << ' ';
				cout << endl;
			}
		}
#endif

		~Solution() {
			DelArray(array);
			DelArray(area);
#ifdef DEBUG
			DelArray(tmp);
#endif
		}
};

int main() {
	int num;
	cin >> num;

	Solution s(num);
	s.Run();

#ifdef DEBUG
	cout <<	endl;
	s.Print();
	cout <<	endl;
#endif
	cout << s.Result() << endl;
}
