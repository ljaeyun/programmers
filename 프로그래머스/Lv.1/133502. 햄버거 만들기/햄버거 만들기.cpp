#include <string>
#include <vector>

using namespace std;

int CheckHam(vector<int> checkHam, int answer, int beforeIndex);

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> temp;

	for (int i = 0; i < ingredient.size(); i++)
	{
		temp.push_back(ingredient[i]);

		if (temp.size() >= 4)
		{
			if (temp.at(temp.size()-1) == 1 && temp.at(temp.size() - 2) == 3 && temp.at(temp.size() - 3) == 2 && temp.at(temp.size() - 4) == 1)
			{
				answer++;

				temp.pop_back();
				temp.pop_back();
				temp.pop_back();
				temp.pop_back();
			}
		}

	}
    
    return answer;
}

