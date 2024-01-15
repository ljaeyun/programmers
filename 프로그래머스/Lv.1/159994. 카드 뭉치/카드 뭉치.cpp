#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    int count = 0;
    for (int i = 0; i < goal.size(); i++)
    {
        auto goalValue = goal[i];
        if (cards1.front() == goalValue)
        {
            cards1.erase(cards1.begin());
            count++;
        }
        else if (cards2.front() == goalValue)
        {
            cards2.erase(cards2.begin());
            count++;
        }
    }

    if (cards1.size() == 0 && cards2.size() == 0)
    {
        answer = "Yes";
    }
    else if (goal.size() == count)
    {
        answer = "Yes";
    }
    else
    {
        answer = "No";
    }
    
    return answer;
}