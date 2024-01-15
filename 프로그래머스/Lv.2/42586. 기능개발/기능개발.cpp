#include <string>
#include <vector>
#include<math.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<int> work_vec;
    
     for (int i = 0; i < progresses.size(); i++)
    {
        int a = progresses[i];
        int b = speeds[i];
        int temp = ceil((float)(100 - a) / b);
        work_vec.push_back(temp);
    }
    int popCount;

    while (!work_vec.empty())
    {
        popCount = 0;
        for(auto&w : work_vec)
            w-=1;
        
        for (auto& w : work_vec)
        {
            

            if (work_vec.front() <= 0)
            {
                work_vec.erase(work_vec.begin());

                popCount++;
            }
        }
        
        if (popCount != 0)
            answer.push_back(popCount);
    }
    
    return answer;
}