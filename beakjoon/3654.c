#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
	int white;
	int black;
}colorSet;

typedef struct
{
	int maxRow;
	int maxCol;
}Table;

void InitSet(colorSet* SetArray);
void CountColor(colorSet* set, char* block);
void CheckBlock(char** block, char**  dept, int maxRow, int maxCol);
void InitDept(char* dept, int maxCol);
void CountDept(char** block, char** dept, int row, int maxCol);

int size;

int main()
{
	char*** blockArray;
	char*** dept;
	
	colorSet* setArray;
	Table* table;

	scanf("%d", &size);

	blockArray = (char***)malloc(sizeof(char**)*size);
	dept = (char***)malloc(sizeof(char**)*size);
	setArray = (colorSet*)malloc(sizeof(colorSet)*size); 
	table = (Table*)malloc(sizeof(Table)*size);

	for(int num = 0; num < size; num++)
	{
		scanf("%d %d", &table[num].maxRow, &table[num].maxCol);
		blockArray[num] = (char**)malloc(sizeof(char*)*table[num].maxRow);
		dept[num] = (char**)malloc(sizeof(char*)*table[num].maxRow);
		
		for(int row = 0; row < table[num].maxRow; row++)
		{
			blockArray[num][row] = (char*)malloc(sizeof(char)*(table[num].maxCol + 1));
			dept[num][row] = (char*)malloc(sizeof(char)*(table[num].maxCol));
			InitDept(dept[num][row], table[num].maxCol);

			scanf("%s", blockArray[num][row]);

			CountDept(blockArray[num], dept[num], row, table[num].maxCol);
			CountColor(&setArray[num], blockArray[num][row]);
		}
	}

	for(int num = 0; num < size; num++)
	{
		if(setArray[num].white != setArray[num].black*2)
		{
			printf("%d %d\n", setArray[num].white, setArray[num].black);
			printf("NO\n");
		}
		else
		{
			CheckBlock(blockArray[num], dept[num], table[num].maxRow, table[num].maxCol);
		}
	}
}


void InitSet(colorSet* setArray)
{
	for(int i = 0; i < size; i++)
	{
		setArray[i].white = 0;
		setArray[i].black = 0;
	}
}

void InitDept(char* data, int maxCol)
{
	for(int i = 0; i <maxCol; i++)
	{
		data[i] = 0;
	}
}

void CountColor(colorSet* set, char* block)
{
	for(int i = 0; block[i] != 0; i++)
	{
		if(block[i] == 'W') (*set).white++;
		else if(block[i] == 'B') (*set).black++;
	}
}

void CountDept(char** block, char** dept, int row, int maxCol)
{
	for(int i= 0; i < maxCol; i++)
	{
		if(block[row][i] == 'W')
		{
			if(row > 0 && block[row -1][i] =='B') dept[row - 1][i]++;
		
			if(i > 0 && block[row][i -1] == 'B') dept[row][i - 1]++;
			if(i < maxCol - 1 && block[row][i + 1] == 'B') dept[row][i + 1]++;
		}
		else if(block[row][i] == 'B')
		{
			if(row >0  && block[row - 1][i] =='W') dept[row][i]++;
		}
	}
}

void CheckBlock(char** block, char** dept, int maxRow, int maxCol)
{
	for(int row = 0; row < maxRow; row++)
	{
		for(int col = 0; col < maxCol; col++)
		{
			if(block[row][col] == 'B' && dept[row][col] < 2)
			{
				printf("NO\n");
				return;
			}
		}
	}

	printf("YES\n");
}
