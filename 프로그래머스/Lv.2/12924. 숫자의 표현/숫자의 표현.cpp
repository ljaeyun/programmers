#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int startNum = 1;
    
    int temp = 0;
    int plusNum = 1;
    while (true)
    {
        temp += plusNum;
        plusNum++;
        if (temp == n)
        {
            answer++;
            startNum++;
            temp = 0;
            plusNum = startNum;
        }
        else if (temp > n)
        {
            startNum++;
            temp = 0;
            plusNum = startNum;
        }

        if (startNum == 10001)
            break;  

    }
    
    return answer;
}