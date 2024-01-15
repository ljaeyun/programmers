#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
    return a+b > b+a; 
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string>temp;
    for(int i = 0 ; i < numbers.size(); i++)
    {
        temp.push_back(to_string( numbers[i]));
    }
    
    sort(temp.begin(), temp.end(), cmp);
    
    if(temp.front() == "0")
        return "0";
    
    for(auto str : temp)
    {
        answer += str;
    }
    
    return answer;
}