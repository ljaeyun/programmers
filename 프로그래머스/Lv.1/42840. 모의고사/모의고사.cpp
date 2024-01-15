#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
     // case 1
    // 1 2 3 4 5 ...
    // case 2
    // 2 1 2 3 2 4 2 5 ...
    // case 3
    // 3 3 1 1 2 2 4 4 5 5 
    vector<int> case1 = { 1, 2, 3 ,4, 5 };
    vector<int> case2 = { 2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> case3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;

    for (int i = 0; i < answers.size(); i++)
    {        
        if (answers[i] == case1[i % case1.size()])
        {
            count1++;
        }
        if (answers[i] == case2[i % case2.size()])
        {
            count2++;
        }
        if (answers[i] == case3[i % case3.size()])
        {
            count3++;
        }
    }

    
    int maxCount = 0;
    
    maxCount = max(count1, count2);
    maxCount = max(maxCount, count3);

    if (maxCount == count1)
        answer.push_back(1);
    if (maxCount == count2)
        answer.push_back(2);
    if (maxCount == count3)
        answer.push_back(3);
    
    return answer;
}