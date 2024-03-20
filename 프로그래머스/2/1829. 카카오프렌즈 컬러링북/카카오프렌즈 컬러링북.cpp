#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

int x_dir[4] = { -1, 0, 1, 0 };
int y_dir[4] = { 0, -1, 0, 1 };

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    int visited_picture[101][101];
    memset(visited_picture, 0, sizeof(visited_picture));
    
    queue<pair<int, int>> picture_q;
        
    int high_area = 0;
    for(int i = 0 ; i < picture.size(); i++)
    {
        for(int j = 0 ; j < picture[i].size(); j++)
        {
            if(visited_picture[i][j] == 0 && picture[i][j] != 0)
            {
                int high_area = 1;
                visited_picture[i][j] = 1;
                picture_q.push(make_pair(i, j));
                
                while(!picture_q.empty())
                {
                    int temp_x = picture_q.front().first;
                    int temp_y = picture_q.front().second;
                    
                    picture_q.pop();
                    
                    for(int g = 0; g < 4 ; g++)
                    {
                        int next_x = temp_x + x_dir[g];
                        int next_y = temp_y + y_dir[g];

                        if(0 <= next_x && next_x < picture.size() && 0 <= next_y && next_y < picture[0].size() && picture[next_x][next_y] == picture[i][j])
                        {
                            if (visited_picture[next_x][next_y] == 0)
                            {
                                visited_picture[next_x][next_y] = 1;

                                picture_q.push(make_pair(next_x, next_y));
                                high_area++;
                            }
                        }
                    }
                }
                ++number_of_area;
                if(high_area > max_size_of_one_area)
                {
                    max_size_of_one_area = high_area;
                }
            }
        }
    }
    
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}