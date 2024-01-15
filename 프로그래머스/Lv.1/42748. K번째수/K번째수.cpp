#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
       for (int i = 0; i < commands.size(); i++)
    {
        vector<int> temp;  // 잘라질 배열 저장

        temp.assign(array.begin() + commands[i][0]-1, array.begin() + commands[i][1]);

        sort(temp.begin(), temp.end());

        answer.push_back(temp.at(commands[i][2]-1));
    }
    
    return answer;
}