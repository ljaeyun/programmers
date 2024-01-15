#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int startIndex = 0;

for (int i = 0; i < number.size() - k; i++)
{

    int maxNum = number[startIndex] - '0';
    int maxIndex = startIndex;

    for (int j = startIndex; j <= i + k; j++)
    {
        if (maxNum < number[j] - '0')
        {
            maxNum = number[j] - '0';
            maxIndex = j ;                
        }
    }
    
    startIndex = maxIndex + 1;
    answer += to_string(maxNum);
}
    
    return answer;
}