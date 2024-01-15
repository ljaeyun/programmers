#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, double>& a, const pair<int, double>& b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    int totalSize = stages.size();
    map<int, int> clearInfo;

    // 초기화
    for (int i = 1; i <= N; i++)
    {
        clearInfo.insert({ i, 0 });
    }
    // 클리어 인원 확인
    for (int i = 0; i < stages.size(); i++)
    {
        if (clearInfo.find(stages[i]) != clearInfo.end())
        {
            clearInfo.find(stages[i])->second += 1;
        }
    }
    // 실패율 계산
    map<int, double> failureRate;
    

    for (auto& it : clearInfo)
    {
        failureRate.insert({it.first, ((double)it.second / totalSize) });

        totalSize -= it.second;
    }

    // 정렬
    vector<pair<int, double>>vec(failureRate.begin(), failureRate.end());

    stable_sort(vec.rbegin(), vec.rend(), cmp);

    for (int i = 0; i < vec.size(); i++)
    {
        answer.push_back(vec[i].first);
    }
    
    return answer;
}