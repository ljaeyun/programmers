#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    
    
    vector<int> ss;

    int beforIndex = 0;
    for (int i = 0; i < s.size(); i++)
    {
        // 공백으로 구분
        if (s[i] == ' ')
        {
            string temp = s.substr(beforIndex, i - beforIndex);
            
            beforIndex = i;

            ss.push_back(stoi(temp));
        }
        if (i == s.size() - 1)
        {
            string temp = s.substr(beforIndex, i );

            beforIndex = i;

            ss.push_back(stoi(temp));
        }
    }
    
    answer += to_string(min_element(ss.begin(), ss.end())[0]);
    answer += " ";
    answer += to_string(max_element(ss.begin(), ss.end())[0]);
    
    return answer;
}