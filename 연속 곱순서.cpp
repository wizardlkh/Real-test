#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;
int N, cnt = 0; 
long long D[1000001][15]; // 15! < 10^12
bool vst[1000001][15];
vector<int> v;
//priority_queue<long long, vector<long long>, greater<long long>> pq; // 내림차순
set<long long> s;

int main()
{
	cin >> N;

	for (int i = 1; i < 1000001; i++)
		D[i][1] = i;

	// DP생성
	for (int i = 1; i < 1000000; i++)
	{
		for (int j = 2; j < 15; j++)
		{	
			D[i][j] = D[i][j - 1] * (long long)(i + j - 1);

			if (D[i][j] > 1000000000000LL)
				break;

			s.insert(D[i][j]);

			//cout << D[i][j] << ' ';
		}
		//cout << '\n';
	}

	for (set<long long>::iterator it = s.begin(); it != s.end(); it++)
	{
		cnt++;
	
		cout << cnt << ": "<< *it << ' ';
 
		if (cnt % 10 == 0)
			cout << '\n';

		if (cnt == N)
		{
			//cout << *it << '\n';
			break;
		}	
	}

	return 0;
}