#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> graph(n+1);

    for (int i = 0; i < edge.size(); i++)
    {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }

    vector<bool> isVisited;
    isVisited.assign(n + 1, false);
    vector<int> count(n + 1, 0);
    queue<int> q;

    q.push(1);
    isVisited[1] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if (!isVisited[next])
            {   
                int temp = count[cur] + 1;
                q.push(next);
                isVisited[next] = true;
                count[next] = temp;
            }
        }
    }

    int maxValue = max_element(count.begin(), count.end())[0];

    for (auto& it : count)
    {
        if (it != 0 &&it == maxValue)
            answer++;
    }
    
    return answer;
}