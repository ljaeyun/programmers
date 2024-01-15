#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    int tempRemain = 0;

    while (true)
    {
        if (n >= a)
        {
            tempRemain = n % a;
            n /= a;
            answer += (n * b);
            n = (n * b);
            n += tempRemain;
        }
        else
        {
            break;  
        }
    }
    
    return answer;
}