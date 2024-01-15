#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    
     int dp[501][501] = { 0, };

    dp[0][0] = triangle[0][0];
    dp[1][0] = triangle[1][0] +dp[0][0];
    dp[1][1] = triangle[1][1] + dp[0][0];

    for (int i = 2; i < triangle.size(); i++)
    {
        dp[i][0] = triangle[i][0] + dp[i - 1][0];
        dp[i][triangle[i].size() - 1] = triangle[i][triangle[i].size() - 1] + dp[i - 1][triangle[i - 1].size() - 1];
    }

    
    for (int i = 2; i < triangle.size(); i++)
    {
        for (int j = 1; j < triangle[i].size()-1; j++)
        {
            dp[i][j] = max( triangle[i][j] + dp[i - 1][j-1], triangle[i][j] + dp[i-1][j]);
        }

    }
      for (int i = 0; i < triangle[triangle.size() - 1].size(); i++)
    {
        answer = max(answer, dp[triangle.size()-1][i]);
    }
    return answer;
}