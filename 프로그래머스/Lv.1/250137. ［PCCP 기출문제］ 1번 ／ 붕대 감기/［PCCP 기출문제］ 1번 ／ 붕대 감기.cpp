#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health;
    
    int timeIndex = 0;
    int streak = 0;
    for(int i = 1 ; i <= attacks[attacks.size()-1][0] ; i++)
    {
        if(attacks[timeIndex][0] == i)
        {
            answer -= attacks[timeIndex][1];
            timeIndex++;
            
            if(answer <= 0)
            {
                return -1;
            }
            streak = 0;
            continue;
        }
        
        answer = min(answer + bandage[1], health);
        streak++;
        
        if(streak == bandage[0])
        {
            answer = min(answer + bandage[2], health);
            
            streak = 0;
        }
        
    }
    
    return answer;
}