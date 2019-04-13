#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> bubbleSort(vector<int> arr, vector<float> arr2, int size);
vector<int> bubbleSort2(vector<int> arr, vector<float> arr2, int size);

vector<int> solution(int N, vector<int> stages) 
{
	vector<int> vecStageNum(N), vecFailNum(N);
	for (int i = 0; i < stages.size(); i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (stages[i] >= j) // 도달한사람
			{
				vecStageNum[j-1] += 1;
				if (stages[i] == j)
				{
					vecFailNum[j-1] += 1; // 못깬사람
				}
			}
		}
	}
	vector<float> vecFailValue(N);
	for (int i = 0; i < N; i++)
	{
		/*vecFailValue[i] = vecFailNum[i] / vecStageNum[i];*/
		float failNum = vecFailNum[i];
		float StageNum = vecStageNum[i];
		vecFailValue[i] = failNum / StageNum;
	}

	vector<int> answer(N);
	for (int i = 0; i < N; i++)
	{
		answer[i] += (1+i);
	}
	
	answer = bubbleSort2(answer, vecFailValue, N);

	return answer;
}

vector<int> bubbleSort(vector<int> arr, vector<float> arr2, int size)
{
	bool isSwap;
	do
	{
		isSwap = false;
		for (int i = 1; i < size; i++)
		{
			if (arr2[i - 1] < arr2[i])
			{
				swap(arr2[i - 1], arr2[i]);
				swap(arr[i - 1], arr[i]);
				isSwap = true;
			}
		}
	} while (isSwap);

	return arr;
}

vector<int> bubbleSort2(vector<int> arr, vector<float> arr2, int size)
{
	for (int i = 1; i <= size; i++)
	{
		for (int j = 0; j < (size-(i)); j++)
		{
			if (arr2[j] < arr2[j + 1])
			{
				swap(arr2[j], arr2[j + 1]);
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	return arr;

}