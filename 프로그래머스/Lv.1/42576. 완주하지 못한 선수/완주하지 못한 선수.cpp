#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> participant_map;
    int count = 0;
    // map 에 데이터 삽입
    for (int i = 0; i < participant.size(); i++)
    {
        

        if (participant_map.find(participant[i]) != participant_map.end())
        {
            participant_map.find(participant[i])->second += 1;
        }
        else
        {
            participant_map.insert({ participant[i], 0 });
        }
    }

    // completion 비교
    for (int i = 0; i < completion.size(); i++)
    {
        if (participant_map.find(completion[i]) != participant_map.end())
        {
            participant_map.find(completion[i])->second = participant_map.find(completion[i])->second - 1;           
        }
    }

    for (auto& d : participant_map)
    {
        if (d.second == 0)
        {
            answer = d.first;
        }
    }
    
    return answer;
}