#include<iostream>
#include<cmath>

using namespace std;

class Simulation
{
	private:
		int now_gold;
		int now_silver;
		int now_copper;

		int after_gold;
		int after_silver;
		int after_copper;

		int count = 0;
	
		void UperChange(int& highCoin, int& lowCoin, int num)
		{
			highCoin += num;
			lowCoin -= 11*num;
			count += num;
		}

		void LowerChange(int& highCoin, int& lowCoin, int num)
		{
			highCoin -= num;
			lowCoin += 9*num;
			count += num;
		}

	public:
		void SetNowMoney() { cin >> now_gold >> now_silver >> now_copper; }
		void SetAfterMoney() { cin >> after_gold >> after_silver >> after_copper; }

		void ChangeOfCoin()
		{
			int copper_diff = after_copper - now_copper;
			if(copper_diff > 0) { LowerChange(now_silver, now_copper, ceil((float)copper_diff/9.0)); }
			
			int gold_diff = after_gold - now_gold;
			if(gold_diff > 0) { UperChange(now_gold, now_silver, gold_diff); }

	
			int silver_diff = after_silver - now_silver;
			gold_diff = now_gold - after_gold;
			if(silver_diff > 0)
			{
				if(silver_diff >= gold_diff*9) LowerChange(now_gold, now_silver, gold_diff);
				else LowerChange(now_gold, now_silver, ceil((float)silver_diff/9.0));
			}

			silver_diff = after_silver - now_silver;
			copper_diff = now_copper - after_copper;
			if(silver_diff > 0)
			{
				if(copper_diff >= silver_diff*11) UperChange(now_silver, now_copper, silver_diff);
			}

			if(after_silver > now_silver) count = -1;

		}

		int Result() { return count; }

		Simulation() {};
};

int main(int argc, char** argv)
{
	Simulation simul;

	simul.SetNowMoney();
	simul.SetAfterMoney();

	simul.ChangeOfCoin();

	cout << simul.Result();

	return 0;
}