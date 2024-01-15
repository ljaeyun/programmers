#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int answerCount = 0;
    int zeroCount = 0;
while (s != "1")
{
    string tempString = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            zeroCount++;
        }
        else
        {
            tempString.push_back(s[i]);
        }
    }

    // tempString 의 크기를 2진수로 변환
    s = "";
    int tempStringSize = tempString.size();
    while (tempStringSize != 0)
    {
        if (tempStringSize % 2 == 1)
            s.push_back('1');
        else
            s.push_back('0');

        tempStringSize /= 2;
    }
    reverse(s.begin(), s.end());

    answerCount++;
}
    
    answer.push_back(answerCount);
    answer.push_back(zeroCount);
    
    return answer;
}