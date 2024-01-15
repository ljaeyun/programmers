#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
 vector<int> facto;

facto.push_back(0);
facto.push_back(1);


int index = 2;
while (index-1 != n)
{
    int a = facto[index - 2];
    int b = facto[index - 1];

    int sumFacto = (a + b) % 1234567;
    facto.push_back(sumFacto);
    index++;
}

answer = facto[n ];
    return answer;
}