#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int maxWidth = 0;
    int maxHeight = 0;
    
    int temp = 0;
    for(int i = 0 ; i < sizes.size(); i++)
    {
        if(sizes[i][0] < sizes[i][1])
        {
            temp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = temp;
        }
    }
    
    
    for(int i = 0 ; i< sizes.size(); i++)
    {
        if(maxWidth < sizes[i][0])
        {
            maxWidth = sizes[i][0];
        }
        if(maxHeight < sizes[i][1])
        {
            maxHeight = sizes[i][1];
        }
    }
    answer = maxWidth * maxHeight;

    return answer;
}