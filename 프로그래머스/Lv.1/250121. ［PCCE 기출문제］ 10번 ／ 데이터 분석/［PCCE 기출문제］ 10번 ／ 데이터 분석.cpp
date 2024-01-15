#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int index = 0;
bool cmp(vector<int> a, vector<int> b)
{
    if(a[index] > b[index])
    {
        return true;
    }
    
    return false;
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    int sortIndex = 0;
    int extIndex = 0;
    string sortStandard[4] = {"code", "date", "maximum", "remain"};
    
    for(int i = 0 ; i < 4; i++)
    {
        if(ext == sortStandard[i])
        {
            extIndex = i;
        }
        if(sort_by == sortStandard[i])
        {
            sortIndex = i;
        }
    }
    
    for(int i = 0 ; i < data.size(); i++)
    {        
        if(data[i][extIndex] < val_ext)
        {
            answer.push_back(data[i]);
        }        
    }
    index = sortIndex;
        
    sort(answer.rbegin(), answer.rend(), cmp);
    
    return answer;
}