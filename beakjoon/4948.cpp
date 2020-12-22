#include<iostream>
#include<cmath>

using namespace std;

bool* GetPrime(int max)
{
	bool* prime = new bool[2*max + 1];
	
	for(int i = 2; i <= 2*max; i++)
	{
		for(int j = 2; j <= sqrt(i); j++)
		{
			if((!prime[j])&&((i %  j)== 0))
			{
				prime[i] = true;
				break;
			}
		}
	}

	return prime;
}

class Prime
{
	private:
		int num;
		Prime* next;
	public:
		void SetNext(Prime* _next) { next = _next; }
		Prime* GetNext() { return next; }

		void ShowPrime(bool* _prime)
		{
			int count = 0;

			for(int i = num + 1; i <= 2*num; i++)
				if(!_prime[i]) count++;
			cout << count <<endl;
		}

		Prime(int _num):num(_num), next(NULL) {}
};

int main()
{
	int num;
	int max = -99999;

	Prime* head = NULL;
	Prime* tmp = NULL;

	bool* prime;

	for(cin >> num; num != 0; cin >> num)
	{
		if(max < num) max = num;

		if(head == NULL)
		{
			head = new Prime(num);
			tmp = head;
		}
		else
		{
			tmp->SetNext(new Prime(num));
			tmp = tmp->GetNext();
		}
	}

	prime = GetPrime(max);

	for(tmp = head; tmp != NULL; tmp = tmp->GetNext())
		tmp->ShowPrime(prime);

	return 0;
}

