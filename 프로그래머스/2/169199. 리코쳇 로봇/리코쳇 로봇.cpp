#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int x_dir[4] = { -1, 0, 1, 0 };
int y_dir[4] = { 0, -1, 0, 1 };

int board_count[101][101];

int solution(vector<string> board) {
    int answer = -1;
    
    int start_X = 0; // 시작 x 좌표
    int start_Y = 0; // 시작 y 좌표


    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            board_count[i][j] = 0;
        }
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 'R')
            {
                start_X = j;
                start_Y = i;
            }
        }
    }

    board_count[start_Y][start_X] = 1;

    //queue<int, int> q;
    queue<pair<int, int>> q;
    queue<int> count;

    q.push(make_pair(start_X, start_Y));
    count.push(0);    

    while (!q.empty())
    {

        int temp_x = q.front().first;
        int temp_y = q.front().second;
        int current_count = count.front();
        // Goal 일 경우 끝        

        q.pop();
        count.pop();

        if (board[temp_y][temp_x] == 'G')
        {
            answer = current_count;
            break;
        }

        for (int m = 0; m < 4; m++)
        {            
            int next_x = temp_x + x_dir[m];
            int next_y = temp_y + y_dir[m];


            while (0 <= next_x && next_x < board[0].size() && 0 <= next_y && next_y < board.size() && board[next_y][next_x] != 'D')
            {
                next_x += x_dir[m];
                next_y += y_dir[m];
            }

            if (board_count[next_y - y_dir[m]][next_x - x_dir[m]] == 0)
            {
                board_count[next_y - y_dir[m]][next_x - x_dir[m]] = 1;
                q.push(make_pair(next_x - x_dir[m], next_y - y_dir[m]));
                count.push(current_count + 1);
            }
        }
    }

    
    
    return answer;
}