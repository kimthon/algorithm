#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//밑에서부터 올라오면서 각점 까지의 최대길이를 구한다.

typedef struct edge
{
	int parents;
	int weight;
	int diameter;
	int radius;
}edge;

void InsertEdge(edge* edgeArray, int num);
void getDiameter(edge* edgeArray, int num);

int main()
{
	int num;
	int diameter = 0;
	edge* edgeArray;

	scanf("%d", &num);
	edgeArray = (edge*)(malloc(num*sizeof(edge)));
	memset(edgeArray, 0, num*sizeof(edge));
	
	InsertEdge(edgeArray, num);
	getDiameter(edgeArray, num);

	for(int i = 0; i < num; i++)
	{
		if(edgeArray[i].diameter > diameter) diameter = edgeArray[i].diameter;
	}

	printf("%d\n", diameter);
	
	return 0;
}

void InsertEdge(edge* edgeArray, int num)
{
	int pNode, cNode, weight;

	while(edgeArray[num-1].parents == 0)
	{
		scanf("%d %d %d", &pNode, &cNode, &weight);
		edgeArray[cNode-1].parents = pNode;
		edgeArray[cNode-1].weight = weight;
	}
}

void getDiameter(edge* edgeArray, int num)
{
	int parents;
	int radius;
	
	//마지막 노드부터 올라오면서 가중치를 더한다.
	for(;num > 0; num--)
	{
		parents = edgeArray[num-1].parents;
		radius = edgeArray[num-1].weight + edgeArray[num-1].radius;
		//자기까지 최대 weight + 부모노드까지 weight
		
		if(edgeArray[parents-1].diameter == edgeArray[parents-1].radius)	edgeArray[parents-1].diameter += radius;
		else if(edgeArray[parents-1].diameter - edgeArray[parents-1].radius < radius) edgeArray[parents-1].diameter = edgeArray[parents-1].radius + radius;  
		
		if(edgeArray[parents-1].radius < radius) edgeArray[parents-1].radius = radius;
		//자기까지 최대 weight를 저장한다
	}
}
