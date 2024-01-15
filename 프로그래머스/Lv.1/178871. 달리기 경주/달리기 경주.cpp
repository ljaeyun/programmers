#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

static bool cmp(pair<string, int>& a, pair<string, int>& b)
{
    return a.second < b.second;
}

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
      map<string, int> score;
    map<int, string> temp;
    for (int i = 0; i < players.size(); i++)
    {
        score.insert({ players[i], i });
        temp.insert({ i, players[i] });
    }

    for (int i = 0; i < callings.size(); i++)
    {
        auto callingName = callings[i];

        auto num = score[callingName];
        auto name = temp[num];

        auto frontName = temp[num - 1];
        auto frontNum = score[frontName];        
        
        score[callingName] = frontNum;
        score[frontName] = num;
        temp[num - 1] = name;
        temp[num] = frontName;
    }
    for (int m = 0; m < temp.size(); m++)
    {
        answer.push_back(temp[m]);
    }
    return answer;
}