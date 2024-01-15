#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    deque<pair<int, int>> deque_temp;

for (int i = 0; i < priorities.size(); i++)
{
    deque_temp.push_back(make_pair(i, priorities[i]));
}

int max_value = *max_element(priorities.begin(), priorities.end()); // 최대값
int max_index = max_element(priorities.begin(), priorities.end()) - priorities.begin(); // 최대인덱스

while (true)
{
    int frontValue = deque_temp.front().second; // 앞 값

    if (frontValue < max_value)
    {
        auto tempFront = deque_temp.front(); // 제일 앞의 값 저장
        deque_temp.pop_front(); // 제일 앞의 값 삭제
        deque_temp.push_back(tempFront); // 뒤에 제일 앞의 값 삽입
    }
    else
    {
        answer++;
        if (deque_temp.front().first == location)
        {
            break;
        }
        deque_temp.pop_front(); // 앞의 값 삭제            
        int ddd = 0;
        for (int m = 0; m < deque_temp.size(); m++)
        {
            if (ddd < deque_temp.at(m).second)
            {
                ddd = deque_temp.at(m).second;
            }
        }
        max_value = ddd;
        
    }
}
    
    return answer;
}