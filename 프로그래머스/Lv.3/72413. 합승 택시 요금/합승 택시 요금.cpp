#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    answer = 100001 * n;
int graph[201][201];  

for (int i = 0; i < 201; i++)
{
    for (int j = 0; j < 201; j++)
    {
        graph[i][j] = 100001 * n;
    }
}

for (int i = 0; i < fares.size(); i++)
{
    graph[fares[i][0]][fares[i][1]] = fares[i][2];
    graph[fares[i][1]][fares[i][0]] = fares[i][2];            
}

for (int k = 0; k <= n; k++)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        }
    }
}

for (int i = 1; i < n + 1; i++)
{
    graph[i][i] = 0;
}

for (int i = 1; i < n + 1; i++)
{
    answer = min(graph[s][i] + graph[i][a] + graph[i][b], answer);
}
    
    return answer;
}