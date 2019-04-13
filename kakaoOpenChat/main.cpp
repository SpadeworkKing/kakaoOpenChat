
#include <string>
#include <vector>

#include "StageClear.h"
#include "openchat.h"

using namespace std;


#define _DEBUG_ 2


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

#endif

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	return 0;
}
