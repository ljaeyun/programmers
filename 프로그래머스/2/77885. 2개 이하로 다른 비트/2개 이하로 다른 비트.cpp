#include <string>
#include <vector>
#include <bitset>
#include <cmath>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    vector<long long> min_number;

    for (long long i = 0; i < numbers.size(); i++)
    {
        long long number = numbers[i];

        bitset<64> origin_bit(number);

        if (number % 2 == 0)
        {
            min_number.push_back(number + 1);
        }
        else
        {
            long long bit = 1;
            
            while (true) {
                if ((numbers[i] & bit) == 0) break;
                bit *= 2; 
            }
            bit = bit / 2;
            
            min_number.push_back(numbers[i] + bit);
        }
    }
    
    return min_number;
}