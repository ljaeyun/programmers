#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int count = -1;
    for(int i =0 ; i< s.length() ; i++)
    {      
        if(int(s[i]) == 32)
        {
            count = -1;
        }
        else
        {
            count++;
        }
        if(count % 2 == 0)
        {
            if(int(s[i]) >= 97)
            {
                s[i] = char(s[i] - 32);
            }
            else
            {
                
            }
        }
        else if(count % 2 == 1)
        {
            if(int(s[i]) >= 97)
            {
                
            }
            else
            {
                s[i] = char(s[i] + 32);
            }
        }
    }
    answer = s;
    
    return answer;
}