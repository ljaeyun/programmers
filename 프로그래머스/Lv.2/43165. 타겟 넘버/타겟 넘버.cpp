#include <string>
#include <vector>

using namespace std;

void sumDFS(vector<int>numbers, int sum, int depth, int target);
int answer = 0;
int solution(vector<int> numbers, int target) {
    
    
    sumDFS(numbers, numbers[0], 0, target);
    sumDFS(numbers, -numbers[0], 0, target);
    return answer;
}

void sumDFS(vector<int>numbers, int sum, int depth, int target)
{
    if(depth == numbers.size()-1)
    {
        if(sum == target)
            answer++;
        return;
    }
    
    sumDFS(numbers, sum + numbers[depth+1], depth+1, target);
    sumDFS(numbers, sum - numbers[depth+1], depth+1, target);
}