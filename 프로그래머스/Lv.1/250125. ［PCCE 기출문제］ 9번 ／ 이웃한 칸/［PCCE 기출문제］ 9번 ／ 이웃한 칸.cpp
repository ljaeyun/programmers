#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    string currentColor = board[h][w];
    
            for(int m = 0 ; m< 4; m++)
            {                
                if((h+dx[m] >= 0 && h+dx[m] < board.size()) && (w+dy[m] >= 0 && w + dy[m] < board.size()))
                {
                string newColor = board[h+dx[m]][w+dy[m]];                
                if(newColor == currentColor)
                {
                    answer++;
                }
                    
                }
            }        
    
    return answer;
}