#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    vector<int> queue;
    for (auto& it : operations)
    {
        if (it[0] == 'I') // 삽입
        {
            auto tempString = it.substr(2, it.size()-1);
            
            queue.push_back(stoi(tempString));
            
        }
        else if (it[0] == 'D') // 삭제
        {
            if (it[2] == '-') // 최솟값 삭제
            {
                if (queue.size() > 0)
                {
                    auto minValue = min_element(queue.begin(), queue.end());
                    queue.erase(remove(queue.begin(), queue.end(), minValue[0]), queue.end());
                }
            }
            else if (it[2] == '1') // 최댓값 삭제
            {
                if (queue.size() > 0)
                {
                    auto maxValue = max_element(queue.begin(), queue.end());
                    queue.erase(remove(queue.begin(), queue.end(), maxValue[0]), queue.end());
                }
            }
            
        }
    }
    
    if (queue.size() == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(max_element(queue.begin(), queue.end())[0]);
        answer.push_back(min_element(queue.begin(), queue.end())[0]);
    }
    
    
    return answer;
}