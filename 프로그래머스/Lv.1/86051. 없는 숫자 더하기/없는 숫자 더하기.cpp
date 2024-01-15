#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    vector<int> nums = { 1,2,3,4,5,6,7,8,9 };
    
    for (auto &n : nums)
    {
        if (find(numbers.begin(), numbers.end(), n) == numbers.end())
        {
            answer += n;
        }
    }
    
    return answer;
}