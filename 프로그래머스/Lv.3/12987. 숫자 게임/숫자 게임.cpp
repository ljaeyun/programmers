#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = -1;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int score = 0;
    int aIndex = 0;
    for (int i = 0; i < B.size(); i++)
    {
        if (A[aIndex] < B[i])
        {
            aIndex++;
            score++;
        }
    }
    answer = score;
    
    return answer;
}