#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> record)
{
	vector<string> vStatus(record.size()), vId(record.size()), vName(record.size());

	for (int i = 0; i < record.size(); i++) // 상태, 아이디, 닉네임 따로저장
	{
		string strStatus, strid, strName;
		int nValue = 0;
		for (int j = 0; j < record[i].size(); j++)
		{
			if (nValue == 0)
			{
				if (record[i][j] == ' ')
				{
					nValue += 1;
					j += 1;
				}
				else
				{
					strStatus += record[i][j];
					vStatus[i] = strStatus;
				}
			}
			if (nValue == 1)
			{
				if (record[i][j] == ' ')
				{
					nValue += 1;
					j += 1;
				}
				else
				{
					strid += record[i][j];
					vId[i] = strid;
				}
			}
			if (nValue == 2)
			{
				if (record[i][j] == ' ')
				{
					nValue += 1;
					j += 1;
				}
				else
				{
					strName += record[i][j];
					vName[i] = strName;
				}
			}
		}

	}

	vector<string> vChangeId(record.size());
	for (int i = 0; i < vStatus.size(); i++) // 아이디 바뀐사람~
	{
		if (vStatus[i] == "Change")
		{
			vChangeId[i] = vId[i];
		}
	}

	for (int i = 0; i < vChangeId.size(); i++)
	{
		if (vChangeId[i] != "")
		{
			for (int j = 0; j < i; j++)
			{
				if (vId[j] == vChangeId[i] && vStatus[j] != "Leave")
				{
					vName[j] = vName[i];
				}
			}
		}
	}

	for (int i = 0; i < vStatus.size(); i++)
	{
		if (vStatus[i] == "Leave" && vName[i] == "")
		{
			for (int j = 0; j < i; j++)
			{
				if (vId[j] == vId[i])
				{
					vName[i] = vName[j];
				}

			}

		}
	}

	for (int i = 0; i < vStatus.size(); i++)
	{
		if (vStatus[i] == "Enter")
		{
			for (int j = 0; j < i; j++)
			{
				if (vId[i] == vId[j])
				{
					vName[j] = vName[i];
				}
			}
		}
	}

	vector<string> answer;
	for (int i = 0; i < vStatus.size(); i++)
	{
		if (vStatus[i] != "Change")
		{
			if (vStatus[i] == "Enter")
			{
				answer.push_back(vName[i] + "님이 들어왔습니다.");
			}
			else if (vStatus[i] == "Leave")
			{

				answer.push_back(vName[i] + "님이 나갔습니다.");
			}
		}
	}


	return answer;
}

