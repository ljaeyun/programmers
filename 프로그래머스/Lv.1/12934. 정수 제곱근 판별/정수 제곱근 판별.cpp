#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    double temp = sqrt(n);

    if (sqrt(n) - (int)sqrt(n) == 0)
    {
        answer = pow(sqrt(n) + 1, 2);
    }
    else
    {
        answer = -1;
    }
    
    return answer;
}