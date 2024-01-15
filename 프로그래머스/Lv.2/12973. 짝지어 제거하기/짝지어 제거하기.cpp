#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
    int answer = -1;

    stack<int> st;
    st.push(s[0]);
    for(int i = 1 ; i < s.size(); i++)
    {
        if(!st.empty())
        {
            if(st.top()==s[i])
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        else
        {
            st.push(s[i]);
        }
    }

    answer = st.size() == 0 ? 1 : 0;
    return answer;
}