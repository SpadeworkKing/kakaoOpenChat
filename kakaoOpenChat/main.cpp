
#include <string>
#include <vector>

#include "StageClear.h"
#include "openchat.h"
#include "CandidateKey.h"

using namespace std;

// 1=openchat, 2=StageClear, 3=CandidateKey
#define _DEBUG_ 3


int main(void)
{

#if _DEBUG_ == 1	///////////////////////////////////////////// openchat

	vector<string> v;
	v.push_back("Enter uid1234 Muzi");
	v.push_back("Enter uid4567 Prodo");
	v.push_back("Leave uid1234");
	v.push_back("Enter uid1234 Prodo");
	v.push_back("Change uid4567 Ryan");

	v = solution(v);

#elif _DEBUG_ == 2	///////////////////////////////////////////// StageClear

	int n = 5;
	vector<int> v;
	v.push_back(2);
	v.push_back(1);
	v.push_back(2);
	v.push_back(6);
	v.push_back(2);
	v.push_back(4);
	v.push_back(3);
	v.push_back(3);

	v = solution(n,v);

#elif _DEBUG_ == 3	///////////////////////////////////////////// CandidateKey

	vector<vector<string>> doubleV;
	int result;
	vector<string> V = { "100", "ryan", "music", "2" };
	doubleV.push_back(V);
	V = { "200", "apeach", "math", "2" };
	doubleV.push_back(V);
	V = { "300", "tube", "computer", "3" };
	doubleV.push_back(V);
	V = { "400", "con", "computer", "4" };
	doubleV.push_back(V);
	V = { "500", "muzi", "music", "3" };
	doubleV.push_back(V);
	V = { "600", "apeach", "music", "2" };
	doubleV.push_back(V);



	result = solution(doubleV);

#endif

// 	for (int i = 0; i < doubleV.size(); i++)
// 	{
// 		for (int j = 0; j < V.size(); j++)
// 		{
// 			cout << doubleV[i][j]<<" " ;
// 		}
// 		cout << endl;
// 	}
	
	/*doubleV[5].pop_back();*/
	
	for (int i = 0; i < doubleV.size(); i++)
	{
		for (int j = 0; j < V.size(); j++)
		{
			cout << doubleV[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
