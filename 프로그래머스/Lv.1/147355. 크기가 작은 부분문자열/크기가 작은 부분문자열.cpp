#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
     int numCount = p.size();

    for (int i = 0; i <= t.size() - numCount; i++)
    {
        string temp = "";
        for (int m = 0; m < numCount; m++)
        {
            temp += t[m+i];
        }
        
        if (temp <= p)
        {
            answer++;
        }
    }
    return answer;
}