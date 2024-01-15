#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;

   int count = 0;

	bool isClosed = false;

	int openCount = 0;
	int closeCount = 0;

	if (s[0] == ")"[0])
	{
		answer = false;
	}
	else if (s[s.size() - 1] == "("[0])
	{
		answer = false;
	}
	else
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == "("[0])
			{
				count++;
				openCount++;
			}

			if (s[i] == ")"[0])
			{
				count--;
				closeCount++;
			}

			if (count != 0 && (openCount < closeCount))
			{
				answer = false;
				break;
			}
		}
		if (s.size() == 0)
			answer = false;
		else if (count == 0)
			answer = true;
		else
			answer = false;		
	}

    return answer;
}