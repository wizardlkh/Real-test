#include <string>
#include <vector>
#include <map>
#include <cstdio>

using namespace std;

vector<string> solution(vector<string> record) {

	map<string, string> map_un;
	char com[11], uid[11], nick[11], temp[50];

	for (auto iter = record.begin(); iter != record.end(); iter++)
	{
		sscanf(iter->c_str(), "%s%s%s", com, uid, nick);

		if (com[0] == 'E' || com[0] == 'C')
			map_un[uid] = nick;
	}

	vector<string> answer;
	for (auto iter = record.begin(); iter != record.end(); iter++)
	{
		sscanf(iter->c_str(), "%s%s", com, uid);

		if (com[0] == 'E')
			sprintf(temp, "%s님이 들어왔습니다.", map_un[uid].c_str());
		else if (com[0] == 'L')
			sprintf(temp, "%s님이 나갔습니다.", map_un[uid].c_str());
		else
			continue;

		answer.push_back(temp);
	}
	return answer;
}