#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    vector<char> skill_stack;

for (int i = 0; i < skill.size(); i++)
{
    skill_stack.push_back(skill[i]);
}

for (int i = 0; i < skill_trees.size(); i++)
{
    vector<char> check_stack;
    bool isSame = true;
    int SameIndex = 0;
    for (int j = 0; j < skill_trees[i].size() ; j++)
    {
        if (isSame == true)
        {
            if (find(skill.begin(), skill.end(), skill_trees[i][j]) != skill.end())
            {
                check_stack.push_back(skill_trees[i][j]);
            }
        }
        else
        {
            break;
        }

        for (int m = SameIndex; m < check_stack.size(); m++)
        {
            if (check_stack[m] != skill_stack[m])
            {
                isSame = false;
                break;
            }
            else
            {
                SameIndex++;
                break;
            }
        }

    }

    if (isSame == true)
        answer++;

}
    
    return answer;
}