#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
   for (int i = 1; i <= r2; i++)
{
    long long y1 = (long long)ceil(sqrt(1.0 *r1 * (long long)r1 -1.0* i * i));
    long long y2 = (long long)floor(sqrt(1.0*r2 * (long long)r2 -1.0* i * i));

    answer += (y2 - y1 + 1);
}
    
    
    
    return answer*4;
}