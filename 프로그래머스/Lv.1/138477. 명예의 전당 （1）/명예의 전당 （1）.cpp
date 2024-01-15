#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    
    vector<int> temp;

    for (int i = 0; i < score.size(); i++)
    {
        
        temp.push_back(score[i]);

        // 정렬
        sort(temp.rbegin(), temp.rend());

        if (i < k)
        {
            answer.push_back(temp.back());
        }
        else
        {
            answer.push_back(temp[k-1]);
        }
    }
    
    return answer;
}