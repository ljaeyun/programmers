#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int tile[60001];
    
    tile[1] = 1;
    tile[2] = 2;
    for(int i = 3; i <= n ; i++)
    {
        tile[i] = (tile[i-1] + tile[i-2]) % 1000000007;
    }

    answer = tile[n];
    
    return answer;
}