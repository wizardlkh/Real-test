#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

typedef vector<set<int, greater<int>>> IntVec; // 내림차순 set 자료형
typedef set<int, greater<int>> IntSet;

bool Compare(const set<int, greater<int>>& firstElem, const set<int, greater<int>>& secondElem)
{
	return *(firstElem.begin()) < *(secondElem.begin()) ;
}

int solution(vector<int> stats)
{
	int answer = 0, bf_max = 0, aft = 0, idx;

	IntVec v;
	IntSet s;

	// 첫번째 값은 셋에 넣음
	s.clear();
	s.insert(stats[0]);
	v.push_back(s);

	for (int i = 1; i < stats.size(); i++)
	{
		// 벡터에 [set의 최대값] 이 작은 순으로 정렬됨
		sort( v.begin(), v.end(), Compare);
		
		// 가장작은 set의 최대값보다 작은수가 들어오면 새 set생성
		if( *(v.begin()->begin()) > stats[i] )
		{
			s.clear();
			s.insert(stats[i]);
			v.push_back(s);
		}
		else
		{
			//v.begin()->insert(stats[i]); 
			//최소 팀수로 하려면 가장 작은데 넣지말고 [들어갈 수 있는 가장 큰 곳]에 insert		
			for(int j=0; j< v.size(); j++)
			{
				if (v.size() == 1)
				{
					v[0].insert(stats[i]);
					break;
				}

				if (*(v[j].begin()) > stats[i])
				{
					v[j - 1].insert(stats[i]);
					break;
				}

				// 마지막셋보다 클 때
				if (j == v.size() - 1)
					v[j].insert(stats[i]);
			}
		}
	}

	answer = v.size();
	return answer;
}



int main()
{
	int n = 6;
	vector<int> stats = { 5, 3, 4, 6, 2, 1 };

	cout << solution(stats) << '\n';


	return 0;
}
