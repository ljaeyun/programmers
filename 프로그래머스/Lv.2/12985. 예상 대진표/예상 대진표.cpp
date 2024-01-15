#include <iostream>
#include <cmath>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

int tempA = 0;
    int tempB = 0;

    if (a < b)
    {
        tempA = a;
        tempB = b;
    }
    else
    {
        tempA = b;
        tempB = a;
    }

    while (tempA != tempB)
    {
        tempA = (tempA + 1) / 2;
        tempB = (tempB + 1) / 2;
        answer++;
    }
    return answer;
}