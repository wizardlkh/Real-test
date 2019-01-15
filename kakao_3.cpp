#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>


using namespace std;

int solution(vector<vector<string>> relation);

#define NUM 8

class Set
{
public:
	int set[NUM], num, fidx, ridx;
	void subset(int s[], int k);
	vector<vector<int>> attribute;
	vector<int> line;

	void init(int col);
	void PrintSubSet();
	void InputSet();
};

void Set::init(int col)
{
	fidx = 0;
	num = col;
}


void Set::subset(int s[], int k)
{
	if (k == num)
	{
		for (int i = 0; i < k; i++)
			if (s[i] == 1)
				line.push_back( set[i] );

		attribute.push_back(line);
		line.clear();
	}
	else
	{
		s[k] = 1;
		subset(s, k + 1);
		s[k] = 0;
		subset(s, k + 1);
	}
}

void Set::InputSet()
{
	for (int i = 0; i < num; i++)
		set[i] = i+1 ;
}

void Set::PrintSubSet()
{
	int* s;
	s = new int[num];

	subset(s, 0);
}

bool Compare(const vector<int>& firstElem, const vector<int>& secondElem)
{
	return firstElem.size() < secondElem.size();
}





int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<string>> relation;
	vector<string> push;

	relation.clear();

	push.clear();
	push.push_back("100");
	push.push_back("ryan");
	push.push_back("music");
	push.push_back("2");
	relation.push_back(push);

	push.clear();
	push.push_back("200");
	push.push_back("apeach");
	push.push_back("math");
	push.push_back("2");
	relation.push_back(push);

	push.clear();
	push.push_back("300");
	push.push_back("tube");
	push.push_back("computer");
	push.push_back("3");
	relation.push_back(push);

	push.clear();
	push.push_back("400");
	push.push_back("con");
	push.push_back("computer");
	push.push_back("4");
	relation.push_back(push);

	push.clear();
	push.push_back("500");
	push.push_back("muzi");
	push.push_back("music");
	push.push_back("3");
	relation.push_back(push);

	push.clear();
	push.push_back("600");
	push.push_back("apeach");
	push.push_back("music");
	push.push_back("2");
	relation.push_back(push);

	/*
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << relation[i][j] << ' ';

		cout << '\n';
	}
	*/

	// �Լ� ȣ��
	solution(relation);


	return 0;
}




int solution(vector<vector<string>> relation) 
{
	int answer = 0, row, col, del=0;
	bool uniq, minimal;
	string one = "";
	map<string,int> mp; // ���ϼ� (�ߺ�) ���� �Ǵ�
	vector<int> uniq_att; // ���ϼ� �����ϴ� attribute�� ��(row) idx ����
	vector<vector<int>> mini; // �ּҼ� �Ǵ�



	// tuple ����
	row = relation.size();

	// �Ӽ� attribute ����
	col = relation[0].size();
	
	// �Ӽ��� ���� �κ����� ����
	Set a;
	a.init(col);
	a.InputSet();

	a.PrintSubSet();

	/*
	// �Ӽ� �κ����� ��� Ȯ��
	for (int i = 0; i < a.attribute.size(); i++)
	{
		for (int j = 0; j < a.attribute[i].size(); j++)
			cout << a.attribute[i][j] << ' ';

		cout << '\n';
	}
	*/
	
	// �� �κ����ո���
	for (int i = 0; i < a.attribute.size(); i++)
	{
		// relation�� �� �ึ��
		for (int k = 0; k < row; k++)
		{
			for (int j = 0; j < a.attribute[i].size(); j++)
			{
				one += relation[k][ a.attribute[i][j] - 1 ];
			}

			mp[one]++;
			one.clear();
		}

		// ���ϼ� Ȯ��
		uniq = true; // ���ϼ� �����Ѵ� ����

		for(auto it : mp)
			if (it.second != 1)
			{
				uniq = false; // �ߺ��Ǵ°� �߰ߵǸ� ���ϼ� �Ҹ���
				break;
			}
		mp.clear();
		
		// ���ϼ� ���� ��, �Ӽ�(attribute) �ప ����
		if (uniq == true)
			uniq_att.push_back(i);
	}

	// ���ϼ� ��� Ȯ��
	for (auto iter = uniq_att.begin(); iter != uniq_att.end(); iter++)
		mini.push_back(a.attribute[*iter]);
	
	sort(mini.begin(), mini.end(), Compare );

	// ������ ���ĵ����� ->  2,3,4,7 ->    2, 7   
	for (auto iter = mini.begin(); iter != mini.end(); iter++)
	{
		for (auto it = iter->begin(); it != iter->end(); it++)
			cout << *it << ' ';
		
		cout << '\n';
	}

	set<int> next;


	
	// �κ����� ���� iter : �񱳱���(����), cp_iter : �񱳴��(����)
	for (auto iter = mini.begin(); iter != mini.end(); iter++)
	{
		if ( (iter+1) == mini.end() )
			break;

		for(auto cp_iter = iter + 1; cp_iter != mini.end(); cp_iter++)
		{
			// set �� ������ ���� �� �ְ�
			for (auto it2 = cp_iter->begin(); it2 != cp_iter->end(); it2++)
				next.insert(*it2);

			minimal = true; // ������ ������ �κ������̶� ����

			for(auto it = iter->begin(); it != iter->end(); it++)
				if (next.find(*it) == next.end()) // set�� ���� ������
				{
					minimal = false;
					break;
				}

			// ������ ������ �κ������̸�
			if (minimal == true)
			{
				mini.erase(cp_iter); //cp_iter �� ����Ű�� vector<int> �����ϸ� �ݺ��� ��ü�� �� �� ����
				iter = mini.begin();
				cp_iter = iter;
			}

			next.clear();
		}
	}

	//cout << mini.size() << '\n';
	answer = mini.size();

	return answer;
}