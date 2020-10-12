#include<iostream>
using namespace std;

int main()
{
	char c_cost[10] = { 0 };
	char maxLength = 0;

	int cost;

	cin >> cost;

	do
	{
		c_cost[maxLength++] = cost%10;
		cost = cost/10;
	}while(cost > 0);

	if((c_cost[maxLength-1] == 1)&& (c_cost[maxLength-2] == 0))
		maxLength--;

	cout << (int)maxLength;

	return 0;
}
