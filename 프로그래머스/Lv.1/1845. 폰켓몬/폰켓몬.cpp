#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
     // 최대 선택가능한 횟수
    int max_selectNum = nums.size() / 2;

    sort(nums.begin(), nums.end());

    // 벡터 중복 제거
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    if (max_selectNum > nums.size())
    {
        answer = nums.size();
    }
    else if (max_selectNum < nums.size())
    {
        answer = max_selectNum;
    }
    else if (max_selectNum == nums.size())
    {
        answer = nums.size();
    }
    
    return answer;
}