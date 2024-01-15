#include <string>
#include <vector>

using namespace std;

vector<int> factor(int a);

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for (int i = 1; i <= number; i++)
	{
		int tempPower = factor(i).size();
		if (tempPower > limit)
		{
			answer += power;
		}
		else
		{
			answer += tempPower;
		}
	}
    
    return answer;
}


vector<int> factor(int a)
{
	vector<int> temp;

	if (a > 0)
	{
		for (int i = 1; i <= a / 2; i++)
		{
			if (a % i == 0)
			{				
				temp.push_back(i);
			}
		}		
		temp.push_back(a);

	}
	return temp;
}