#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    for (int i = 0; i < targets.size(); i++)
    {
        auto target = targets[i];
        int te = 0;
        for (int m = 0; m < target.size(); m++)
        {
            auto t = target[m];
            int findIndex = 0;
            vector<int> indexList;
            for (int j = 0; j < keymap.size(); j++)
            {
                auto findResult = find(keymap[j].begin(), keymap[j].end(), t);
                if (findResult != keymap[j].end()) // 찾았을 경우
                {
                    indexList.push_back(findResult - keymap[j].begin() + 1);
                }
            }
            if (indexList.size() > 0)
            {
                int min = *min_element(indexList.begin(), indexList.end());
                te += min;
            }
            else
            {
                te = -1;
                break;
            }
        }
        answer.push_back(te);
    }
    
    return answer;
}