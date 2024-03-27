#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    stack<int> num_stack;
    
    for(int i = numbers.size()-1; i >= 0; i--)
    {
        while(true)
        {
            if(num_stack.empty())
            {
                answer.push_back(-1);
                break;
            }
            if(num_stack.top() > numbers[i])
            {
                answer.push_back(num_stack.top());
                break;
            }
            num_stack.pop();
        }
        num_stack.push(numbers[i]);
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}