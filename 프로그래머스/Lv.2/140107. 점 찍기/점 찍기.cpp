#include <string>
#include <vector>
#include<math.h>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    for (int i = 0; i <= d; i += k)
	{
		int maxY = sqrt(pow(d, 2) - pow(i, 2));
		answer += ceil(maxY / k) + 1;
	}
    return answer;
}