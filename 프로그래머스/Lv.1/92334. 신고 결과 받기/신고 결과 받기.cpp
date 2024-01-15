#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    multimap<string, string> reportMap;
    string stringBuffer;
    string str1;
    string str2;
    
    set<string> cloneReport(report.begin(), report.end());

    
    for(auto &cr : cloneReport)
    {
        istringstream splitString(cr);
        splitString >> str1 >> str2;
        reportMap.insert(pair<string, string>(str2, str1));
    }
    
    vector<string> id_list2;
    
    for(auto &i : id_list)
    {
        if(reportMap.count(i) >= k)
        {
            for(auto &rm : reportMap)
            {
                if(rm.first == i)
                {
                    id_list2.push_back(rm.second);
                }
            }
        }
    }
    
    for(auto &mm : id_list)
    {
        answer.push_back(count(id_list2.begin(), id_list2.end(), mm));
    }
    
    return answer;
}