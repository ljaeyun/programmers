#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    vector<int> xValue;
    vector<int> yValue;

    for (int i = 0; i < wallpaper.size(); i++)
    {
        for (int j = 0; j < wallpaper[i].size(); j++)
        {
            if (wallpaper[i][j] == '#')
            {                
                xValue.push_back(i);
                yValue.push_back(j);
            }
        }
    }
    
    int minValue = min_element(xValue.begin(), xValue.end())[0];
    int maxValue = max_element(xValue.begin(), xValue.end())[0];
    
    int minValue2 = min_element(yValue.begin(), yValue.end())[0];
    int maxValue2 = max_element(yValue.begin(), yValue.end())[0];

    answer.push_back(minValue);
    answer.push_back(minValue2);
    answer.push_back(maxValue + 1);
    answer.push_back(maxValue2 + 1);
    
    return answer;
}