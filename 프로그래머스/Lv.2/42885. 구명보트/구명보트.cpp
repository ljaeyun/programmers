#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
     sort(people.begin(), people.end());

    int leftIndex = 0;
    int rightIndex = people.size() - 1;


    while (leftIndex <= rightIndex)
    {
        if (leftIndex == rightIndex)
        {
            answer++;
            break;
        }
        if (people[leftIndex] + people[rightIndex] <= limit)
        {
            answer++;
            rightIndex--;
            leftIndex++;
        }
        else
        {
            answer++;
            rightIndex--;
        }
    }
    
    return answer;
}