#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;


string solution(string phrases, int second) 
{
	string answer = "";
	int len = phrases.size();

	const char * cp;
	cp = new char[len];
	cp = phrases.c_str();
	char temp;

	deque<char> dq;

	// 길이 len의 2배인 dq만들기
	for (int i = 0; i < len; i++)
		dq.push_back('_');
	for (int i = 0; i < len; i++)
		dq.push_back(cp[i]);
	
	for (int i = 1; i <= second; i++)
	{
		temp = dq.front();
		dq.pop_front();
		dq.push_back(temp);
	}

	for (int i =0; i< len; i++)
		answer.push_back(dq[i]);

	return answer;
}

int main()
{
	string s1 = "happy-birthday";
	int n =3 ;

	cout << solution(s1, n) << '\n';


	return 0;
}