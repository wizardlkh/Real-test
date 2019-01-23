#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int block_num = 0;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int pic[101][101];
bool vst[101][101];


void dfs(int x, int y, int color)
{
	int nx, ny;
	vst[x][y] = true;
	
	block_num++;

	for (int i = 0; i < 4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];

		if (vst[nx][ny] == false && pic[nx][ny] == color)
			dfs(nx, ny, color);
	}
}

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	int row = picture.size() , col = picture[0].size();
	
	// 전역변수 초기화
	for(int i=0; i<row; i++)
		for (int j = 0; j < col; j++)
		{
			pic[i][j] = picture[i][j];
			vst[i][j] = false;
		}

	for (int i = 0; i<row; i++)
		for (int j = 0; j < col; j++)
		{
			// 방문안됬고 색있음
			if (vst[i][j] == false && pic[i][j] != 0)
			{
				dfs(i,j,pic[i][j]);

				number_of_area++;
				max_size_of_one_area = max(max_size_of_one_area , block_num);
				block_num = 0;
			}
		}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;

	return answer;
}


int main()
{
	int m=6, n=4;
	vector<vector<int>> picture = { {1, 1, 1, 0},{1, 2, 2, 0},{1, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 3},{0, 0, 0, 3 } };
	vector<int> prt;

	prt = solution(m, n, picture);

	cout << prt[0] << '\n';
	cout << prt[1] << '\n';

	return 0;
}