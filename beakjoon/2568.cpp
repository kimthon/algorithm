#include<iostream>

using namespace std;

class Line
{
	private:
		int* start;
		int* end;

		int MaxDept = 0;
		int* deptArray;

		int size;

		void LIS()
		{
			int* deptNumArray = new int[size];
			MaxDept = -1;

			InitDept(1001);

			for(int i = 0; i < size; i ++)
			{
				int dept = FindDept(deptNumArray, end[i]);

				deptArray[i] = dept;
				deptNumArray[dept] = end[i];

				if((MaxDept + 1) == dept) MaxDept++;
			}

			delete deptNumArray;
		}

		void sort(int left, int right)
		{
			int p = (left + right)/2;

			int bigLeft = left;
			int smallRight = right;

			while(true)
			{
				//기준 보다 큰 왼쪽값과 기준보다 작은 오른쪽 값을 찾는다.
				while(start[bigLeft] < start[p]) bigLeft++;
				while(start[p] < start[smallRight]) smallRight--;

				//찾은 두 값의 위치를 바꿔준다.
				if(bigLeft <= smallRight)
				{
					swap(start, bigLeft, smallRight);
					swap(end, bigLeft, smallRight);

					bigLeft++;
					smallRight--;
				}else break;
			}

			if(left < smallRight) sort(left, smallRight);
			if(bigLeft < right) sort(bigLeft, right); 
		}

		void swap(int* array, int first, int second)
		{
			int tmp = array[first];
			array[first] = array[second];
			array[second] = tmp;
		}

		int FindDept(int* array, int num)
		{
			int front = 0;
			int rior = MaxDept + 1;
			int dept = (MaxDept + 1)/2;

			while(front != rior)
			{
				if(num > array[dept])
				{
					front = dept + 1;
					dept = (dept + rior)/2 + 1;
				}
				else
				{
					rior =  dept;
					dept = (dept + front)/2;
				}

				if(dept > MaxDept) break;
			}
			return dept;
		}

		void InitDept(int num) { for(int i = 0; i < size; i ++) deptArray[i] = num; }

	public:
		Line(int num):start(new int[num]), end(new int[num]), deptArray(new int[num]), size(num)
		{
			for(int i = 0; i < num; i++)
			{
				cin >> start[i] >> end[i];
			}

			sort(0, num - 1);

			LIS();
		}

		void Print()
		{
			int count = MaxDept;
			int delSize = 0;
			int* tmp = new int[size - MaxDept];

			for(int i = size - 1; 0 <= i; i--)
			{
				if(deptArray[i] == count) count--;
				else tmp[delSize++] = start[i];
			}

			cout << delSize + 1 << endl;

			for(int i = delSize - 1; i >= 0 ; i--)
				cout << tmp[i] << endl;
			
			delete tmp;
		}
};

int main()
{
	int size;
	cin >> size;

	Line line(size);
	line.Print();

	return 0;
}
