#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

typedef vector<set<int, greater<int>>> IntVec; // �������� set �ڷ���
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

	// ù��° ���� �¿� ����
	s.clear();
	s.insert(stats[0]);
	v.push_back(s);

	for (int i = 1; i < stats.size(); i++)
	{
		// ���Ϳ� [set�� �ִ밪] �� ���� ������ ���ĵ�
		sort( v.begin(), v.end(), Compare);
		
		// �������� set�� �ִ밪���� �������� ������ �� set����
		if( *(v.begin()->begin()) > stats[i] )
		{
			s.clear();
			s.insert(stats[i]);
			v.push_back(s);
		}
		else
		{
			//v.begin()->insert(stats[i]); 
			//�ּ� ������ �Ϸ��� ���� ������ �������� [�� �� �ִ� ���� ū ��]�� insert		
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

				// �������º��� Ŭ ��
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
