#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    
    for (int i = 3; i < brown; i++)
    {
        for (int j = i; j < brown; j++)
        {
            int temp = i * j;
            int temp2 = temp - brown;
            if (temp2 == yellow && j*2 + (i * 2- 4) + temp2 == brown+yellow )
            {
                answer.push_back(j);
                answer.push_back(i);
            }
        }
    }
    
    return answer;
}