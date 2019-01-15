#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s1, string s2) {
	int answer = 0, min=102, len1=0, len2=0;
	string sub1, sub2;
	

	if (s1.length() >= s2.length())
		min = s2.length();
	else
		min = s1.length();

	size_t size;


	// s1이 앞
	for (int i = 0; i < min; i++)
	{
		sub2.clear();
		sub2 = s2.substr(0, i+1);
		
		sub1.clear();
		sub1 = s1.substr((s1.length() - 1) - i, i + 1);

		if (sub1 == sub2)
			len1 = sub1.length();
	}

	// s2가 앞
	for (int i = 0; i < min; i++)
	{
		sub1.clear();
		sub1 = s1.substr(0, i + 1);

		sub2.clear();
		sub2 = s2.substr((s2.length() - 1) - i, i + 1);

		if (sub1 == sub2)
			len2 = sub2.length();
	}

	if (len1 <= len2)
		answer = len2;
	else
		answer = len1;

	answer = s1.length() + s2.length() - answer;

	return answer;
}




int main()
{
	string s1 = "ababc";
	string s2 = "abcdab";
	int n;

	n = solution(s1, s2);

	cout << n  << '\n';


	return 0;
}