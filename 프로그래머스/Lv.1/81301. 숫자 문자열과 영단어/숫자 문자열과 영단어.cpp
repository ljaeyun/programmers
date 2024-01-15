#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <algorithm>
using namespace std;

int solution(string s) {
    int answer = 0;
    vector<string> numString = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "zero"};
    vector<string> numInt = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "0" };
    
    for(auto a : s)
    {
        
    
    for(auto& ns : numString)
    {
        if(s.find(ns) != s.npos)
        {
            s = s.replace(s.find(ns), ns.length(), numInt[find(numString.begin(), numString.end(), ns) - numString.begin()]);            
        }
    }
    }
    std::stringstream ssInt(s);
    ssInt>> answer;
    return answer;
}