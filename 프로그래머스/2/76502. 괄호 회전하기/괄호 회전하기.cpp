#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for (int i = 0; i < s.size(); i++)
{
    // s 위치 돌리기
    string tempStringA = s.substr(0,i);
    string tempStringB = s.substr(i , s.size() );

    string new_s = tempStringB + tempStringA;
    
    vector<char> small_stack;
    vector<char> mid_stack;
    vector<char> large_stack;

    vector<char> total_stack;

    for (int j = 0; j < new_s.size(); j++)
    {
        total_stack.push_back(new_s[j]);

        if (total_stack.size() > 1)
        {
            auto tempA = total_stack.at(total_stack.size() - 2);
            auto tempB = total_stack.at(total_stack.size() - 1);

            if ((tempA == '(' && tempB == ')') || (tempA == '{' && tempB == '}') || (tempA == '[' && tempB == ']'))
            {
                total_stack.pop_back();
                total_stack.pop_back();
            }
        }
    }

    if (total_stack.empty())
    {
        answer++;
    }
    int dd = 0;
}
    
    return answer;
}