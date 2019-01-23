#include<vector>
#include<queue>
#include<iostream>
#include <tuple>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int visited[101][101];

int solution(vector<vector<int> > maps)
{
	int answer = 0, row = maps.size(), col = maps[0].size(), x=0,y=0, nx=0, ny=0;
	queue<pair<int, int>> xy_q;
	
	xy_q.push(pair<int, int> {0,0});
	visited[0][0] = true;

	while (xy_q.empty() == false)
	{
		tie(x, y) = xy_q.front();
		xy_q.pop();

		//visited[x][y] = true;

		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];

			if ((0 <= nx && nx < row) && (0 <= ny && ny < col))
			{
				if (visited[nx][ny] == false && maps[nx][ny] > 0)
				{					
					visited[nx][ny] = true;
					maps[nx][ny] = maps[x][y] + 1;
					xy_q.push(make_pair( nx,ny ));
				}
			}
		}
	}
	if (maps[row - 1][col - 1] == 1)
		answer = -1;
	else
		answer = maps[row - 1][col - 1];

	return answer;
}


int main()
{
	vector<vector<int> > maps = { { 1, 0, 1, 1, 1 }, { 1, 0, 1, 0, 1 }, { 1, 0, 1, 1, 1 }, { 1, 1, 1, 0, 1 }, { 0, 0, 0, 0, 1 } };
	vector<vector<int> > maps2 = { {1, 0, 1, 1, 1},{1, 0, 1, 0, 1},{1, 0, 1, 1, 1},{1, 1, 1, 0, 0},{0, 0, 0, 0, 1} };

	cout << solution(maps)<< '\n';


	return 0;
}
