#include <string>
#include <vector>
#include <queue>


using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
     priority_queue<int> works_queue(works.begin(), works.end());
    
    for (int i = 0; i < n; i++)
    {
        if (works_queue.top() > 0)
        {
            int highValue = works_queue.top() - 1;
            works_queue.pop();
            works_queue.push(highValue);
        }
    }
    
    while (!works_queue.empty())
    {
        answer += works_queue.top() * works_queue.top();
        works_queue.pop();
    }
    
    return answer;
}