#include<stdio.h>
#include<stdlib.h>

typedef struct point
{
	int lPoint;
	int rPoint;
}point;

int Combination(int n, int r)
{
	if(n == r || r == 0) return 1;
	else return Combination(n, r -1)*(n -r + 1)/r;
}

int main()
{
	int num;
	int sum;
	point* pointArray;

	scanf("%d", &num);
	pointArray = (point*)malloc(sizeof(point)*num);
	
	for(int i = 0; i < num; i++)
	{
		scanf("%d %d", &pointArray[i].lPoint, &pointArray[i].rPoint);
	}

	for(int i = 0; i < num; i++)
	{
		sum =  Combination(pointArray[i].rPoint, pointArray[i].lPoint);
		printf("%d\n", sum);
	}

	return 0;
}
