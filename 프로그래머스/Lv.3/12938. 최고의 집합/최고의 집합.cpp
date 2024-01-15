#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    // n = 숫자의 개수
    // s = 숫자들의 합 
    int temp = s / n;
    int temp2 = n - s % n;

    if (temp == 0)
    {
        answer.push_back(-1);
        return answer;  
    }

  

    for (int i = 0; i < temp2; i++)
    {
        answer.push_back(temp);
    }

    for (int i = temp2; i < n; i++)
    {
        answer.push_back(temp + 1);
    }
    return answer;
}