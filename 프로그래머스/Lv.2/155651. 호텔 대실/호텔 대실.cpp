#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    int imos[60*24+10] = {0,};
    
    for(int i = 0 ; i< book_time.size(); i++)
    {
        int startTime = stoi(book_time[i][0].substr(0, 2)) * 60 + stoi(book_time[i][0].substr(3, 2));
int endTime = stoi(book_time[i][1].substr(0, 2)) * 60 + stoi(book_time[i][1].substr(3, 2));
        
        imos[startTime] += 1;
        imos[endTime + 10] -= 1;
    }
    
    int tempSum = 0;
    int room = 0;
    for(int i = 0 ; i< 60*24 ; i++)
    {
        tempSum += imos[i];
        room = max(tempSum, room);
    }
    answer = room;
    return answer;
}