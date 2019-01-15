#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

int solution(vector<int> estimates, int k) {
	int answer = 0, len = 0, sum1, sum2=0;
	len = estimates.size();

	for (int i = 0; i <= len - k; i++)
	{
		sum1 = 0;

		for (int j = i; j < i + k; j++)
			sum1 += estimates[j];

		if(sum1 > sum2)
			sum2 = sum1;
	}

	answer = sum2;

	return answer;
}




int main()
{
	vector<int> estimates = { 1, 1, 9, 3, 7, 6, 5, 10 };
	int k = 4;

	cout << solution(estimates, k) << '\n';


	return 0;
}