#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int GetBinaryOneCount(int n)
{
    // 2진수 변환
    string tempString = "";
    int oneCount = 0;
    while (n != 0)
    {
        if (n % 2 == 1)
        {
            tempString.push_back('1');
            oneCount++;
        }
        else
        {
            tempString.push_back('0');
        }

        n /= 2;
    }
    reverse(tempString.begin(), tempString.end());

    return oneCount;
}

int solution(int n) {
    int answer = 0;
    
    answer = n + 1;

int nOneCount = GetBinaryOneCount(n);
while (true)
{
    int currentCount = GetBinaryOneCount(answer);

    if (nOneCount == currentCount)
    {
        break;
    }
    else
    {
        answer++;
    }
}
    
    return answer;
}