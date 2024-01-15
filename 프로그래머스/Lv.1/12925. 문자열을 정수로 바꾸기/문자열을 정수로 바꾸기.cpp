#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    answer = stoi(s);
    
    /*bool isMinus = false;
    for(int i = 0 ; i < s.size(); i++)
    {
        // 부호가 있을 경우
        if(s[i] == '+')
        {
            //answer += ((s[i] - '0') * pow(10, s.size()-1-i));
            continue;
        }
        else if(s[i] == '-')
        {
            
            isMinus = true;
        }
        else // 전부 숫자
        {
            answer += ((s[i] - '0') * pow(10, s.size()-1-i));
        }
    }
    
    if(isMinus)
    {
        answer *= -1;
    }*/
        
    
    return answer;
}