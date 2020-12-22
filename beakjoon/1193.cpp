#include<iostream>
using namespace std;

class Fraction
{
	private:
		int mother; //분모
		int son; //분자

		void SetDetailNum(int adjust)
		{
			son -= adjust;
			mother += adjust;
		}

		void Swap()
		{
			int tmp = son;
			son = mother;
			mother = tmp;
		}
	public:
		Fraction(int num) : mother(1), son(1)
		{
			int tmp = 1;
			bool even;

			//몇 번째 대각선인지 계산
			for(int i = 2; tmp < num; i++)
			{
				tmp += i;
				son++;
			}

			//홀수, 짝수 라인 구별
			even = !(son%2);
			
			//정확한 값으로 조정
			SetDetailNum(tmp - num);

			if(even) Swap();
		}
		
		void Show()
		{
			cout << mother << "/" << son;
		}
};

int main()
{
	int num;
	cin >> num;

	Fraction tmp(num);
	tmp.Show();

	return 0;
}