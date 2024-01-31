#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int maxElement(int a, int b, int c)
{
    int max;


if (a > b)
{
    if (a > c)
    {
        max = a;
    }
    else
    {
        max = c;
    }
}
else
{
    if (c > b)
    {
        max = c;
    }
    else
    {
        max = b;
    }
}

    return max;
}

int solution(vector<vector<int> > land)
{
    int answer = 0;

    for (int i = 1; i < land.size(); i++)
    {

        land[i][0] += maxElement(land[i - 1][1], land[i - 1][2], land[i - 1][3]);
        land[i][1] += maxElement(land[i - 1][2], land[i - 1][3], land[i - 1][0]);
        land[i][2] += maxElement(land[i - 1][0], land[i - 1][1], land[i - 1][3]);
        land[i][3] += maxElement(land[i - 1][0], land[i - 1][1], land[i - 1][2]);
    }

    answer = max_element(land[land.size()-1].begin(), land[land.size()-1].end())[0];
    return answer;
}