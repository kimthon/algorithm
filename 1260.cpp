#include<iostream>
#include<queue>
#include<stack>

using namespace std;

class Graph
{
	private:
		int vertexCount;
		int lineCount;
		int startVertex;

		bool** matrix;

		void SetMatrix(int vertexCount)
		{
			matrix = new bool*[vertexCount];
			for(int i = 0; i < vertexCount; i++)
				matrix[i] = new bool[vertexCount];
			InitMatrix(false, vertexCount);
		}
		
		void InitMatrix(bool _bool, int vertexCount)
		{
			for(int i = 0; i < vertexCount; i++)
				for(int j = 0; j < vertexCount; j++)
					matrix[i][j] = _bool;
		}

		void SetFS(int& presentVertex, bool*& checker)
		{
			presentVertex = startVertex - 1;
			checker = new bool[vertexCount];

			for(int i = 0; i < vertexCount; i++) checker[i] = false;

			checker[startVertex - 1] = true;
			cout << presentVertex +1;
		}

		bool const AllTrue(bool* checker)
		{
			for(int i = 0; i < vertexCount; i++)
				if(!checker[i]) return false;
			return true;
		}

		bool const isLeafNode(int& i, int& vertexCount) { return (i == vertexCount); }
		bool const isCanLining(bool& used, bool& canLine) { return (!used) && (canLine); }
	public:
		void DFS()
		{
			stack<int> s;

			int presentVertex;
			bool* checker;

			SetFS(presentVertex, checker);
			
			while(!AllTrue(checker))
			{
				for(int i = 0; i <= vertexCount; i++)
				{
					if(isLeafNode(i, vertexCount))
					{
						presentVertex = s.top();
						s.pop();
						break;
					}
					else if(isCanLining(checker[i],matrix[presentVertex][i]))
					{
						s.push(presentVertex); 
						
						presentVertex = i;
						cout << " " << presentVertex + 1;
						checker[presentVertex] = true;
						break;
					}
				}
			}
			cout << endl;

			delete checker;
		}

		void BFS()
		{
			queue<int> q;

			int presentVertex;
			bool* checker;

			SetFS(presentVertex, checker);

			while(!AllTrue(checker))
			{
				for(int i = 0; i < vertexCount; i++)
				{
					if(isCanLining(checker[i],matrix[presentVertex][i]))
					{
						q.push(i);

						cout << " " << i + 1;
						checker[i] = true;
					}
				}

				if(!q.empty())
				{
					presentVertex = q.front();
					q.pop();
				}
			}
			delete checker;
		}
		
		Graph()
		{	
			cin >> vertexCount >> lineCount >> startVertex;
		
			SetMatrix(vertexCount);

			//정점을 입력받고 인접행렬을 설정한다.
			int vertex1, vertex2;
			for(int i = 0; i < lineCount; i++)
			{
				cin >> vertex1>> vertex2;
				matrix[vertex1-1][vertex2-1] = true;
				matrix[vertex2-1][vertex1-1] = true;
			}
		}
};

int main()
{
	Graph graph;

	graph.DFS();
	graph.BFS();
}
