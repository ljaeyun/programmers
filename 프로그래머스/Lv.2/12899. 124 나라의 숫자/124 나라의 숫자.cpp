#include <string>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    
   int quot = 0; // 몫
    int remain = 0; // 나머지

    int newNum = n;

    while (newNum != 0)
    {
        quot = newNum / 3;
        remain = newNum % 3;

        if (remain == 0)
        {
            quot -= 1;
            remain = 4;
            answer = to_string(remain) + answer;
        }
        else
        {
            answer = to_string(remain) + answer; 
        }
        newNum = quot;
    }
    
    return answer;
}