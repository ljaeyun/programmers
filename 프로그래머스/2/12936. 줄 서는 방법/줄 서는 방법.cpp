#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    
    vector<int> peopleNum;
    for(int i = 1; i<= n; i++)
    {
        peopleNum.push_back(i);
    }
    
    long long jumpStep = 0;
    k = k-1;
    while(n > 0)
    {
        long long fac = 1;
        for(int i = 1; i <= n-1; i++)
        {
            fac *= i;
        }
        
        jumpStep = k / (fac);
        
        answer.push_back(peopleNum[jumpStep]);
        peopleNum.erase(peopleNum.begin() + jumpStep);
        
        n = n-1;
        k = k % fac;
    }
    
    return answer;
}