#include<iostream>
#include<list>

using namespace std;

//북, 서, 남, 동 순서
int horizon[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int vertical[8] = { -1, -1, 0, 1, 1, 1, 0, -1};

class World
{
	private:
		int width;
		int high;
		int** map;

		int landNum;

		void InitMap()
		{
			for(int x = 0; x < width; x++)
			{
				map[x] = new int[high];
			}
		}

		void SetMap()
		{
			for(int y = 0; y < high; y++)
			{
				for(int x= 0; x < width; x++)
				{
					cin >> map[x][y];
				}
			}
		}

		bool ValidRange(int num, int max)
		{
			if(num < 0) return false;
			if(num >= max) return false;
			return true;
		}

		void FindLand(int x, int y)
		{
			//만약 land가 아니거나 벌써count 되었다면 멈춘다.
			if(map[x][y] != 1) return;
			
			map[x][y] = landNum;
			
			for(int i = 0; i < 8; i++)
			{
				if(ValidRange(x + horizon[i], width)&&ValidRange(y + vertical[i], high))
				{
					FindLand(x + horizon[i], y + vertical[i]);
				}
			}
		}

	public:
		World(int _width, int _high):width(_width), high(_high), map(new int*[_width]), landNum(0)
		{
			InitMap();
			SetMap();

			for(int y = 0; y < high; y++)
			{
				for(int x = 0; x < width; x++)
				{
					if(map[x][y] == 1)
					{
						landNum--;
						FindLand(x, y);
					}
				}
			}
		}

		int LandNum() { return landNum*(-1); }
};

int main(int argc, char** argv)
{
	int width, high;
	list<World*> worldList;

	//최초 값 입력
	cin >> width >> high;
	//0, 0입력 나올때 까지 반복
	while(!(width == 0)&&!(high == 0))
	{
		worldList.push_back(new World(width, high));
		cin >> width >> high;
	}

	list<World*>::iterator tmp;
	for(tmp = worldList.begin(); tmp != worldList.end(); tmp++)
	{
		cout << (*tmp)->LandNum() << endl;
	}

	return 0;
}
