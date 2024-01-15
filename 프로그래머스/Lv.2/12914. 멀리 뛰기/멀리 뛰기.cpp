#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    
    vector<long long> arr;
    
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);

    for (int i = 3; i <= n; i++)
    {
        arr.push_back((arr[i - 1] + arr[i - 2]) % 1234567);
    }
    
    answer = arr[n];
    
    return answer;
}