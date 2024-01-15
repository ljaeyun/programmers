#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isBig(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    int highValue = 0;
    sort(dungeons.begin(), dungeons.end(), isBig);
    
    do
    {
        int clone_k = k;
        highValue = 0;
        for(int i = 0 ; i < dungeons.size(); i++)
        {
            if(dungeons[i][0] <= clone_k)
            {
                clone_k -= dungeons[i][1];
                highValue++;
            }
        }
        
        if(answer < highValue)
        {
            answer = highValue;
        }
    } while(next_permutation(dungeons.begin(), dungeons.end()));
    
    return answer;
    
}