#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
        for (int m = 0; m < numbers.size(); m++)
    {
        for (int n = m+1; n < numbers.size(); n++)
        {
            answer.push_back(numbers[m] + numbers[n]);
        }
    }

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    
    return answer;
}