#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool CountSort(vector<int> a, vector<int> b)
{
    if (a.size() > b.size())
    {
        return false;
    }

    return true;
}
vector<int> solution(string s) {
    vector<int> answer;
    
     vector<vector<int>> newData;

 int openCount = 0;
 int closeCount = 0;
 vector<int> temp2;
 // string 에서 숫자 추출
 string tempNum = "";
 for (int i = 0; i < s.size(); i++)
 {
     if (s[i] == '{')
     {
         openCount++;
     }
     if (s[i] == '}')
     {
         openCount--;
         if (openCount == 1)
         {
             //sort(temp2.begin(), temp2.end());
             temp2.push_back(stoi(tempNum));
             tempNum = "";
             newData.push_back(temp2);
         }
         temp2.clear();
     }

     if (openCount == 2 && s[i] != '{' && s[i] != ' ')
     {
         if (s[i] != ',' )
         {
             tempNum.push_back(s[i]);
         }
         else
         {
             temp2.push_back(stoi(tempNum));
             tempNum = "";
         }            
     }
 }
 // 개수에 따라 정렬
 sort(newData.begin(), newData.end(), CountSort);

 
 for (int i = 0; i < newData.size(); i++)
 {
     for (int j = 0; j < newData[i].size(); j++)
     {
         if (find(answer.begin(), answer.end(), newData[i][j]) == answer.end())
         {
             answer.push_back(newData[i][j]);
         }
     }
 }
    
    return answer;
}