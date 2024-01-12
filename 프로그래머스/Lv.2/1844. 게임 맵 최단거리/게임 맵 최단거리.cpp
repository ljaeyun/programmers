#include<vector>
#include<queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
   
    int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// 거리표시
int check[101][101];

int visited[101][101];

for (int i = 0; i < 101; i++)
{
    for (int j = 0; j < 101; j++)
    {
        visited[i][j] = 0;
        check[i][j] = 0;
    }
}

// 시작
visited[0][0] = 1;
queue<pair<int, int>>q;
q.push(make_pair(0, 0));

while (!q.empty())
{
    int x = q.front().first;
    int y = q.front().second;

    q.pop();

    for (int i = 0; i < 4; i++)
    {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (0 <= next_x && next_x < maps.size() && 0 <= next_y && next_y < maps[0].size())
        {
            if (maps[next_x][next_y] == 1 && visited[next_x][next_y] == 0)
            {
                check[next_x][next_y] = check[x][y] + 1;
                visited[next_x][next_y] = 1;
                q.push(make_pair(next_x, next_y));
            }
        }
    }
}
    if(check[maps.size()-1][maps[0].size()-1] == 0)
    {
        answer = -1;
    }
    else
    {
        answer = check[maps.size()-1][maps[0].size()-1]+1;
    }
    
    
   
    return answer;
}