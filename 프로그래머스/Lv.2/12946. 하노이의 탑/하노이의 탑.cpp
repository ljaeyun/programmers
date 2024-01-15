#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void hanoi(int n, int start, int to, int via)
{
    vector<int> temp;
    if(n==1)
    {
        temp.push_back(start);
        temp.push_back(to);
        answer.push_back(temp);
    }
    else
    {
        hanoi(n-1, start, via, to);
        temp.push_back(start);
        temp.push_back(to);
        answer.push_back(temp);
        hanoi(n-1, via, to, start);
    }
    
}

vector<vector<int>> solution(int n) {
    
    
    hanoi(n, 1, 3, 2);
    
    return answer;
}