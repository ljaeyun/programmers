#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    long long tile[5000];
    
    int p = 1000000007;
    tile[1] = 0;
    tile[2] = 3;
    tile[3] = 0;
    tile[4] = 11;
    
    for(int i = 5 ; i <= 5000; i++)
    {
        if(i % 2 == 1)
        {
            tile[i] = 0;
        }
        else
        {            
            tile[i] = (((tile[i - 2] * 4) % p) - ((tile[i - 4]) % p) + p)%p;
        }
    }
    
    answer = tile[n];
    return answer;
}