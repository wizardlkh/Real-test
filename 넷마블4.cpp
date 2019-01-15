#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;
void drg_init(int * egg, int * drg, int * n_drg, int day, int m_day);
void n_drg_init(int * egg, int * drg, int * n_drg, int day, int m_day);

void egg_init(int * egg, int * drg, int * n_drg, int day, int m_day)
{
	if (day > m_day)
		return ;

	egg[day]++;
	egg[day+1]++;

	drg_init(egg, drg, n_drg, day + 2, m_day);
}

void drg_init(int * egg, int * drg, int * n_drg, int day, int m_day)
{
	if (day > m_day)
		return;

	drg[day]++;
	drg[day+1]++;
	drg[day+2]++;
	drg[day+3]++;

	egg_init(egg, drg, n_drg, day, m_day);
	egg_init(egg, drg, n_drg, day+1, m_day);
	egg_init(egg, drg, n_drg, day+2, m_day);
	egg_init(egg, drg, n_drg, day+3, m_day);

	n_drg_init(egg, drg, n_drg, day + 4, m_day);
}

void n_drg_init(int * egg, int * drg, int * n_drg, int day, int m_day)
{
	if (day > m_day)
		return;

	for (int i = day; i <= m_day; i++)
		n_drg[i]++;
}


int solution(int n)
{
	int answer = 0; // egg_num=1, drg_num=0, n_drg_num=0;
	
	//vector<int> egg, drg, n_drg;
	//egg.push_back(1);

	int * egg, *drg, *n_drg;
	egg = new int[n + 1];
	drg = new int[n + 1];
	n_drg = new int[n + 1];

	for (int i = 0; i <= n; i++)
	{
		egg[i] = 0;
		drg[i] = 0;
		n_drg[i] = 0;
	}

	egg_init(egg, drg, n_drg, 0, n);

	cout << n_drg[n] << ' ' << drg[n] <<' '<< egg[n] << '\n';

	answer = egg[n] + drg[n] + n_drg[n];
	return answer;
}

int main()
{
	int n = 7;

	cout << solution(n)<< '\n';

	return 0;
}
