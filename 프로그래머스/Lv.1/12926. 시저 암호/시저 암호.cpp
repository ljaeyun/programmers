#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
      for (int i = 0; i < s.size(); i++)
    {
        auto temp = s[i];

        if ((int)temp >= 97 && (int)temp <= 122) // 소문자
        {            
            temp + n > 122 ? answer.push_back(char(temp + n - 26)) : answer.push_back(char(temp + n));
        }
        else if((int)temp >= 65 && (int)temp <= 90)
        {
            temp + n > 90 ? answer.push_back(char(temp + n - 26)) : answer.push_back(char(temp + n));
        }
        else
        {
            answer.push_back(char(' '));
        }
    }
    
    return answer;
}