#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    priority_queue<int> pq;

	for (int i = 0; i < enemy.size(); i++)
	{
		int currentEnemy = enemy.at(i);
		pq.push(currentEnemy);

		if (n >= currentEnemy)
		{
			n -= currentEnemy;
			answer++;
		}
		else
		{
			if (k > 0)
			{
				k--;
				answer++;                
				n += pq.top() - currentEnemy;
                pq.pop();				
			}
			else
			{
				break;
			}
		}
	}
    
    return answer;
}