#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    int index = 0;
    
    for(auto & n : absolutes)
    {
        answer = signs[index] == true ? answer +=n : answer -= n;
        index++;
    }
    return answer;
}