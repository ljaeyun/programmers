#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long low = 1; // 최소 시간
    long long high = (long long)max_element(times.begin(), times.end())[0] * n; // 최대 시간

     while (low <= high)
    {

        long long mid = (low + high) / 2;

        long long count = 0;
        for (int i = 0; i < times.size(); i++)
        {
            count += mid / times[i];
        }

        if (count < n)
        {
            low = mid + 1;
        }
        else
        {
            if (mid <= high)
            {
                answer = mid;
            }
            high = mid - 1;
        }

    }
    
    return answer;
}