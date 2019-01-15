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

	// 함수 호출
	solution(relation);


	return 0;
}




int solution(vector<vector<string>> relation) 
{
	int answer = 0, row, col, del=0;
	bool uniq, minimal;
	string one = "";
	map<string,int> mp; // 유일성 (중복) 여부 판단
	vector<int> uniq_att; // 유일성 만족하는 attribute의 행(row) idx 저장
	vector<vector<int>> mini; // 최소성 판단



	// tuple 개수
	row = relation.size();

	// 속성 attribute 개수
	col = relation[0].size();
	
	// 속성에 대한 부분집합 생성
	Set a;
	a.init(col);
	a.InputSet();

	a.PrintSubSet();

	/*
	// 속성 부분집합 출력 확인
	for (int i = 0; i < a.attribute.size(); i++)
	{
		for (int j = 0; j < a.attribute[i].size(); j++)
			cout << a.attribute[i][j] << ' ';

		cout << '\n';
	}
	*/
	
	// 각 부분집합마다
	for (int i = 0; i < a.attribute.size(); i++)
	{
		// relation의 각 행마다
		for (int k = 0; k < row; k++)
		{
			for (int j = 0; j < a.attribute[i].size(); j++)
			{
				one += relation[k][ a.attribute[i][j] - 1 ];
			}

			mp[one]++;
			one.clear();
		}

		// 유일성 확인
		uniq = true; // 유일성 만족한다 가정

		for(auto it : mp)
			if (it.second != 1)
			{
				uniq = false; // 중복되는거 발견되면 유일성 불만족
				break;
			}
		mp.clear();
		
		// 유일성 만족 시, 속성(attribute) 행값 저장
		if (uniq == true)
			uniq_att.push_back(i);
	}

	// 유일성 출력 확인
	for (auto iter = uniq_att.begin(); iter != uniq_att.end(); iter++)
		mini.push_back(a.attribute[*iter]);
	
	sort(mini.begin(), mini.end(), Compare );

	// 사전순 정렬되있음 ->  2,3,4,7 ->    2, 7   
	for (auto iter = mini.begin(); iter != mini.end(); iter++)
	{
		for (auto it = iter->begin(); it != iter->end(); it++)
			cout << *it << ' ';
		
		cout << '\n';
	}

	set<int> next;


	
	// 부분집합 제거 iter : 비교기준(앞행), cp_iter : 비교대상(뒤행)
	for (auto iter = mini.begin(); iter != mini.end(); iter++)
	{
		if ( (iter+1) == mini.end() )
			break;

		for(auto cp_iter = iter + 1; cp_iter != mini.end(); cp_iter++)
		{
			// set 에 다음행 원소 다 넣고
			for (auto it2 = cp_iter->begin(); it2 != cp_iter->end(); it2++)
				next.insert(*it2);

			minimal = true; // 앞행이 뒤행의 부분집합이라 가정

			for(auto it = iter->begin(); it != iter->end(); it++)
				if (next.find(*it) == next.end()) // set에 원소 없으면
				{
					minimal = false;
					break;
				}

			// 앞행이 뒤행의 부분집합이면
			if (minimal == true)
			{
				mini.erase(cp_iter); //cp_iter 가 가르키는 vector<int> 삭제하면 반복자 자체가 쓸 수 없음
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