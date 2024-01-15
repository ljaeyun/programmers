#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    vector<int> basket;
    
    
    for (int m = 0; m < moves.size(); m++)
    {
        int move = moves[m]-1;

        for (int i = 0; i < board.size(); i++)
        {
            auto selectNum = board[i][move];

            if (selectNum == 0)
            {
                continue;
            }
            else
            {
                if (basket.size() != 0)
                {
                    if (basket.back() == selectNum)
                    {
                        basket.pop_back();
                        answer+=2;
                    }
                    else
                    {
                        basket.push_back(selectNum);
                    }
                }
                else
                {
                    basket.push_back(selectNum);
                }
                board[i][move] = 0;
                break;
            }
        }
    }
    
    return answer;
}