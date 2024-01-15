#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;

    bool isPrime[100001];

    fill_n(isPrime, 100001, true);

    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= 100000; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= 100000; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int m = j + 1; m < nums.size(); m++)
            {
                auto num1 = nums[i];
                auto num2 = nums[j];
                auto num3 = nums[m];

                // 소수 판별
                auto sum = num1 + num2 + num3;
                auto result = isPrime[sum];

                if (result == true)
                    answer++;
            }
        }
    }

    return answer;
}