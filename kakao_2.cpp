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
	
	// 함수 호출
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

	// 스테이지별 사람수 입력 -> 스테이지 : 1,2,3,4,6
	for(auto iter = stages.begin(); iter != stages.end(); iter++)
		stage_man[*iter] ++;
	
	man = stages.size();
	total = man;

	// 스테이지별 실패율 입력 (여기서 이미 int에 대한 정렬 완료 -> sort 안해도됨 )
	for (int i = 1; i <= N; i++)
	{
		stage_fail.push_back( pair<int, double>(i, (double)stage_man[i] / (double)total) );
		total -= stage_man[i];
	}
	
	// int에 대한 정렬 
	//sort(stage_fail.begin(), stage_fail.end());
	
	// int에 대한 정렬 유지하면서, 실패율(double형)에 대한 내림차순 정렬
	stable_sort(stage_fail.begin(), stage_fail.end(), pairCompare);
	
	// 최종 결과값을 vector<int> 에 옮기기
	for (int i = 0; i < stage_fail.size() ; i++)
		answer.push_back(stage_fail[i].first);

	return answer;
}