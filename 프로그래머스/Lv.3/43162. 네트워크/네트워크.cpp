#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    queue<int> q;    
    vector<bool> isVisited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!isVisited[i])
        {
            q.push(i);
            answer += 1;

            while (!q.empty())
            {
                int x = q.front();
                q.pop();
                for (int j = 0; j < n; j++)
                {
                    if (computers[x][j] == 1 && !isVisited[j])
                    {
                        isVisited[j] = true;
                        q.push(j);
                    }
                }
            }
        }
    }
    
    return answer;
}