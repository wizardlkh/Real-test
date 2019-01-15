#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

bool pairCompare(const std::pair<int, double>& firstElem, const std::pair<int, double>& secondElem)
{
	return firstElem.second > secondElem.second;
}

vector<int> solution(int N, vector<int> stages);

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 5;
	vector<int> stages;
	
	stages.push_back(2);
	stages.push_back(1);
	stages.push_back(2);
	stages.push_back(6);
	stages.push_back(2);
	stages.push_back(4);
	stages.push_back(3);
	stages.push_back(3);
	
	// �Լ� ȣ��
	vector<int> ans( solution(N, stages) );

	for (auto iter = ans.begin(); iter != ans.end(); iter++)
		cout << *iter << ' ';

	return 0;
}


vector<int> solution(int N, vector<int> stages) 
{
	vector<int> answer;
	map <int, int> stage_man;
	stage_man.clear();
	int man, total;
	
	vector< pair<int,double> > stage_fail;
	stage_fail.clear();

	// ���������� ����� �Է� -> �������� : 1,2,3,4,6
	for(auto iter = stages.begin(); iter != stages.end(); iter++)
		stage_man[*iter] ++;
	
	man = stages.size();
	total = man;

	// ���������� ������ �Է� (���⼭ �̹� int�� ���� ���� �Ϸ� -> sort ���ص��� )
	for (int i = 1; i <= N; i++)
	{
		stage_fail.push_back( pair<int, double>(i, (double)stage_man[i] / (double)total) );
		total -= stage_man[i];
	}
	
	// int�� ���� ���� 
	//sort(stage_fail.begin(), stage_fail.end());
	
	// int�� ���� ���� �����ϸ鼭, ������(double��)�� ���� �������� ����
	stable_sort(stage_fail.begin(), stage_fail.end(), pairCompare);
	
	// ���� ������� vector<int> �� �ű��
	for (int i = 0; i < stage_fail.size() ; i++)
		answer.push_back(stage_fail[i].first);

	return answer;
}