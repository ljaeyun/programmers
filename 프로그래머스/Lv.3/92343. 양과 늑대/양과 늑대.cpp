#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int maxCount = 0;

void dfs4(int x, int y, int z, vector<int> temp, vector<vector<int>> temp2, vector<int>info);

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    int size = info.size();
        
        vector<vector<int>>g(size);
    for (auto s : edges)
    {
        g[s[0]].push_back(s[1]);
    }
    
    vector<int> list;
    list.push_back(0);

    dfs4(0, 0, 0, list, g, info);
    
    return maxCount;
}


void dfs4(int index, int sc, int wc, vector<int> nextPos, vector<vector<int>> g, vector<int>info)
{
    if (info[index] == 0)
        sc++;
    else
        wc++;
    if (wc >= sc) return;
    maxCount = max(maxCount, sc);

    vector<int> list;
    
    list.insert(list.end(), nextPos.begin(), nextPos.end());
    
    list.erase(remove(list.begin(), list.end(), index), list.end());
    
        if (!g.at(index).empty())
        {
            for (auto& child : g.at(index))
            {
                list.push_back(child);
            }
        }
    
    
    
    for (auto& next : list)
    {
        dfs4(next, sc, wc, list, g, info);
    }
}