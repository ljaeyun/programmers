#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
     string temp = "";

    map<string, string> m;
    for (auto& s : record)
    {
        string status;
        string uid;
        string nick;

        // 문자열 자르기
        istringstream splitString(s);
        splitString >> status >> uid >> nick;
        
        if (status == "Enter")
        {
            if (m.find(uid) != m.end())
            {
                m.erase(uid);
                m.insert({ uid, nick });
            }
            else
            {
                m.insert({ uid, nick });
            }
        }
        else if (status == "Change")
        {
            if (m.find(uid) != m.end())
            {
                m.find(uid)->second = nick;
            }
        }
    }

    for (auto &re : record)
    {
        string status;
        string uid;
        string nick;

        
        // 문자열 자르기
        istringstream splitString(re);
        splitString >> status >> uid >> nick;

        if (status == "Enter")
        {
            temp = m.find(uid)->second + "님이 들어왔습니다.";
            answer.push_back(temp);
        }
        else if (status == "Leave")
        {
            temp = m.find(uid)->second + "님이 나갔습니다.";
            answer.push_back(temp);
        }
    }
    
    
    return answer;
}