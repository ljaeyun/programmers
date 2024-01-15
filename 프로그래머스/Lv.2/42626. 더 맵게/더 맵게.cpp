#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    // 우선순위 큐
priority_queue<int, vector<int>, greater<int>> queue_test;

// 데이터 삽입
for (int i = 0; i < scoville.size(); i++)
{
    queue_test.push(scoville[i]);
}


while (true)
{
     // queue의 가장 앞의 값
int front_value = queue_test.top();
    // 7 보다 작은 경우
    if (front_value < K && queue_test.size() > 1)
    {
        queue_test.pop();
        int next_value = queue_test.top();
        queue_test.pop();
        int newScoville = front_value + next_value * 2;

        queue_test.push(newScoville);
        answer++;
        
    }
    else if (front_value >= K )
    {                
        break;
    }
    else
    {
        answer = -1;
        break;
    }
}
 
    return answer;
}