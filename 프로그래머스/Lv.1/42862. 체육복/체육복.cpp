#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
     int suitCount[31];
 fill_n(suitCount, 31, 1);

    for(int i = 0 ; i < lost.size(); i++)
    {
        suitCount[lost[i]-1]--;
    }
    for(int i = 0 ; i < reserve.size();i++)
    {
        suitCount[reserve[i]-1]++;
    }

    for(int i = 0 ; i < n ; i++)
    {
        if(suitCount[i] == 0)
        {
            if(i>0 && suitCount[i-1] == 2)
            {
                suitCount[i-1] = 1;
                suitCount[i] = 1;
            }
            else if(i < n-1 && suitCount[i+1] == 2)                
            {
                suitCount[i+1] = 1;
                suitCount[i] = 1;
            }
        }
    }

 for (int i = 0; i < n; i++)
 {
     if (suitCount[i] >= 1)
     {
         answer++;
     }
 }
    
    return answer;
}