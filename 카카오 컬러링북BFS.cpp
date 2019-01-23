#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

//시간 복잡도: O(n^2)
//공간 복잡도: O(n^2)
//사용한 알고리즘: BFS
//사용한 자료구조: 2차원 배열

int d[101][101];
bool check[101][101];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };
int cnt = 0;
int v = 0, h = 0;


void bfs(int x, int y, int color) 
{
	int nx, ny;
	//check[x][y] = true;
	queue <pair<int, int>> q;
	q.push({ x,y });
	check[x][y] = true;

	while (q.empty() == false)
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		cnt++;

		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];

			if (check[nx][ny] == false && d[nx][ny] == color)
			{
				check[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}

vector<int> solution(int m, int n, vector<vector<int>> picture) 
{
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	v = m;
	h = n;

	for (int i = 0; i<m; i++) 
	{
		for (int j = 0; j<n; j++)
		{
			d[i][j] = picture[i][j];
			check[i][j] = false;
		}
	}

	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++) 
		{
			if (check[i][j] == false && d[i][j] != 0) 
			{
				bfs(i, j, d[i][j]);
				number_of_area++;
				max_size_of_one_area = max(max_size_of_one_area, cnt);
				cnt = 0;
			}
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}


int main()
{
	int m = 6, n = 4;
	vector<vector<int>> picture = { { 1, 1, 1, 0 },{ 1, 2, 2, 0 },{ 1, 0, 0, 1 },{ 0, 0, 0, 1 },{ 0, 0, 0, 3 },{ 0, 0, 0, 3 } };
	vector<int> prt;

	prt = solution(m, n, picture);

	cout << prt[0] << '\n';
	cout << prt[1] << '\n';

	return 0;
}