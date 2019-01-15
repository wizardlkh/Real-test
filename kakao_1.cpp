#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

class SCR
{
public:
	double scr;
	int idx;

	SCR()
	{
	}

	SCR(double scr, int idx) {
		this->scr = scr;
		this->idx = idx;
	}

	// 이 기준으로 SCR벡터 정렬
	bool operator <(SCR &oscr) 
	{
		return this->scr > oscr.scr;
	}
};






using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N=5, idx;

	vector<int> stages;
	//vector<SCR> scr;

	stages.push_back(2);
	stages.push_back(1);
	stages.push_back(2);
	stages.push_back(6);
	stages.push_back(2);
	stages.push_back(4);
	stages.push_back(3);
	stages.push_back(3);

	/*    21262433
	for (int i = 0; i < stages.size() ; i++)
		cout << stages[i] << '\n';
	*/
	

	///////////////////////
	int j = 0;
	double ja, mo;
	vector<SCR> scr;
	vector<int> answer;
	vector<int> human( N+2 ); // 스테이지 개수 +1  , 각 단계에 있는 사람 수 
	//human[1]~[N+1] 사용
	
	fill(human.begin(), human.end(), 0);
	

	for (int i = 0; i < stages.size(); i++)
	{
		idx = stages[i];
		human[idx]++;
	}

	human[0] = 0;

	// 분모 초기화
	mo = stages.size();

	
	// 스테이지 개수만큼 확률 push  scr[0]~[N-1]
	for (int i = 1; i <= N; i++)
	{
		ja = human[i];
		mo -= human[i - 1];
		scr.push_back( SCR( ja / mo , i) );
	}
	
	sort(scr.begin(), scr.end() );

	for (int i = 0; i < scr.size(); i++)
		answer.push_back(scr[i].idx);

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << '\n';
	

	return 0;
}