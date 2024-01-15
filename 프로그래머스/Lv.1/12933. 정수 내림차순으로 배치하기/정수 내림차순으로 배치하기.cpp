#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    vector<long long> arr;
    
    auto temp = n;

    while (true)
    {
        arr.push_back(temp % 10);
        temp /= 10;
        if (temp == 0)
            break;  
    }

    sort(arr.rbegin(), arr.rend());

    for (auto d : arr)
    {
        answer = answer * 10 + d;
    }

    
    return answer;
}