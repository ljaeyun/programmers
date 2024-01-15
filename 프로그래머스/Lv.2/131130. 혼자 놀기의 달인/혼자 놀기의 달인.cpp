#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    vector<int> visited;
	vector<int> boxCount;

	int visitedCard[101] = {0,};	
	for (int i = 0; i < cards.size(); i++) // 순서대로 카드 선택
	{
		int firstNum = cards.at(i);
		int num = cards.at(i);
		vector<int>temp;
		while (visitedCard[num] != 1)
		{
			temp.push_back(cards.at(num - 1));
			visitedCard[num] = 1;
			num = cards.at(num - 1);
			
			if (num == firstNum)
			{
				boxCount.push_back(temp.size());
				break;
			}
		}
	}	
	sort(boxCount.rbegin(), boxCount.rend());	
	if (boxCount.size() > 1)
	{
		answer = boxCount.at(0) * boxCount.at(1);
	}
	else
	{
		answer = 0;
	}
    return answer;
}