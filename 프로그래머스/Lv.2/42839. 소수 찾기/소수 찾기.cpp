#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(long long temp)
{
    for(long long i = 2; i * i <= temp ; i++)
    {
        if(temp % i == 0)
            return false;
    }
    
    return true;
}

int solution(string numbers) {
    int answer = 0;
    
    vector<int> nums;
    vector<char> v;
    
    //numbers의 조합
    for(int i =0; i < numbers.size(); i++)
    {
        v.push_back(numbers[i]);
    }
    sort(v.begin(), v.end());
    
    do
    {
        string str = "";
        for(int i = 0 ; i < v.size(); i++)
        {
            str.push_back(v[i]);
            nums.push_back(stoi(str));
        }
    } while(next_permutation(v.begin(), v.end()));
    
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    for(int i = 0 ; i < nums.size(); i++)
    {
        if(isPrime(nums[i]) && nums[i] != 1 && nums[i]!=0)
        {
            answer++;
        }
    }
    
    return answer;
}