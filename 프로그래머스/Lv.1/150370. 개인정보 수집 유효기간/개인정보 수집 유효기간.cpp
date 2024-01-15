#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
     // 현재 날짜 parsing
    auto currentYear = stoi(today.substr(0, 4));
    auto currentMonth = stoi(today.substr(5, 2));
    auto currentDay = stoi(today.substr(8, 2));

    int currentTotalDay = currentYear * 12 * 28 + currentMonth * 28 + currentDay;

    // 약관 map 저장
    string delimiter = " ";
    size_t pos = 0;
    map<char, int> newTerms;
    for (int i = 0; i < terms.size(); i++)
    {
        string tempString = terms[i];
        while ((pos = tempString.find(delimiter)) != string::npos)
        {
            auto temp = tempString.substr(0, pos);
            tempString.erase(0, pos + delimiter.length());
            newTerms.insert({ *temp.c_str(), (stoi(tempString)) });
        }
    }


    for (int i = 0; i < privacies.size(); i++)
    {
        // privacies parsing
        string tempString = privacies[i];
        int year = stoi(tempString.substr(0, 4));
        int month = stoi(tempString.substr(5, 2));
        int day = stoi(tempString.substr(8, 2));

        string termType = tempString.substr(11, 1);
        auto termMonth = newTerms[*termType.c_str()];

        // 전체 일 수 
        int totalDay = year * 12 * 28 + (month + termMonth) * 28 + day;
        

        if (totalDay <= currentTotalDay)
        {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}