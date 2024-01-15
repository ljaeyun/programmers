#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    int time[100000] = { 0, };

	for (int i = 0; i < prices.size(); i++)
	{
		for (int j = i + 1; j < prices.size(); j++)
		{
			time[i] += 1;
			if (prices.at(j) < prices.at(i))
			{				
				break;
			}			
		}
	}
	
	for (int i = 0; i < prices.size(); i++)
	{
		answer.push_back(time[i]);
	}
    return answer;
}