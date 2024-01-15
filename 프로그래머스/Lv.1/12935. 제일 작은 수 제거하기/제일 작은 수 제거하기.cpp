#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int minValue = 0;
    minValue = arr[0];

    int count = 0;    
    
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < minValue)
        {
            minValue = arr[i];
        }        
    }

    auto result= find(arr.begin(), arr.end(), minValue) - arr.begin();

    arr.erase(arr.begin() + result);

    if (arr.size() == 0)
        answer = { -1 };
    else
        answer = arr;
    
    return answer;
}