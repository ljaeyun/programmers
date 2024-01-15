#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


    int visited[101][101];
    
    int dir_x[4] = {1, -1 ,0 ,0};
    int dir_y[4] = {0, 0, 1, -1};

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    
    
    
    for(int m = 0 ; m < maps.size(); m++)
    {
        for(int n = 0 ; n < maps[0].size(); n++)
        {
            if(maps[m][n] != 'X' && visited[m][n] == 0)
            {
                queue<pair<int, int>> pq;
                pq.push(make_pair(m, n));
                visited[m][n] = 1;
                int sum = 0;
                sum = maps[m][n] - '0';    
                
                while(!pq.empty())
                {
                    int x = pq.front().first;
                    int y = pq.front().second;
                    
                    pq.pop();
                    
                        
                    for(int i = 0 ; i < 4 ; i++)
                    {
                        int next_x = x + dir_x[i];
                        int next_y = y + dir_y[i];
                        
                        if(next_x < 0 || next_x >= maps.size() || next_y < 0 || next_y >= maps[0].size())
                            continue;
                        if(maps[next_x][next_y] == 'X' || visited[next_x][next_y] == 1)
                            continue;
                        
                        visited[next_x][next_y] = 1;
                        pq.push(make_pair(next_x, next_y));

                        sum += (maps[next_x][next_y] - '0');
                        
                    }
                }
                answer.push_back(sum);
            }
        }
    }
    
    if(answer.size() != 0)
    {
        sort(answer.begin(), answer.end());    
    }
    else
    {
        answer.push_back(-1);
    }
    
    
    return answer;
}