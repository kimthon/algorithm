#include<iostream>
#include<climits>
#include<algorithm>
#include<cstring>

using namespace std;

class Solution {
	private:
		int** array = NULL;
		int** area = NULL;
		int size = 0;

		int min = INT_MAX;

		void InitArray(int**& array) {
			if(array != NULL) DelArray(array);

			array = new int*[size];
			for(int i = 0; i < size; ++i)
				array[i] = new int[size];
		}

		int SumResult() {
			int area_sum[5] = {0, 0, 0, 0, 0} ;
			for(int i = 0; i < size; ++i)
				for(int j = 0; j < size; ++j) {
					int area_num = area[i][j];
					int human = array[i][j];
					area_sum[area_num] += human;
				}

			int min = *min_element(area_sum, area_sum + 5);
			int max = *max_element(area_sum, area_sum + 5);

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
				area[x + i][y - i] = 4;
				area[x + d2 + i][y + d2 - i] = 4;
			}

			for(int i = 0; i <= d2; ++i) {
				area[x + i][y + i] = 4;
				area[x + d1 + i][y - d1 + i] = 4;
			}

			//테두리 채우기
			for(int i = 0; i < d1; ++i)
				for(int j = 1; ; ++j)
				{
					int& tmp = area[x + i + j][y - i];
					if(tmp == 4) break;
					tmp = 4;
				}

			for(int i = 1; i < d2; ++i)
				for(int j = 1; ; ++j)
				{
					int& tmp = area[x + i + j][y + i];
					if(tmp == 4) break;
					tmp = 4;
				}

		}

		void DelArray(int** array) {
			for(int i = 0; i < size; ++i)
				delete array[i];
			delete array;
			array = NULL;
		}
	public:
		Solution(int size) {
			this->size = size;

			//SetArray(array);

			InitArray(area);

			SetArea(1,4,3,2);
		}

		int Result() { return min; }

		void Print() {
			for(int i = 0; i < size; ++i)
			{
				for(int j = 0; j < size; ++j)
					cout << area[i][j] << ' ';
				cout << endl;
			}
		}
};

int main() {
	int num;
	cin >> num;

	Solution s(num);

	s.Print();
	//cout << s.Result() << endl;
}
