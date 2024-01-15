#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    
    for (int i = left; i <= right; i++)
    {
        int temp = 0;
        for (int m = 1; m * m <= i; m++)
        {
            if (m * m == i)
            {
                temp++;
            }
            else if (i % m == 0)
            {
                temp += 2;
            }
        }

        if (temp % 2 == 0)
            answer += i;
        else
            answer -= i;
    }
    
    return answer;
}