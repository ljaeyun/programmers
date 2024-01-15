#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    // 유사 큐
vector<string> test_queue;

int start_index = 0;
int total_index = 0;   
for (int i = 0; i < number.size(); i++)
{
    total_index += number[i];
}

while (true)
{
    vector<int> clone_number = number;
    for (int i = start_index; i < discount.size(); i++)
    {
        // 데이터 삽입
        test_queue.push_back(discount[i]);

        // want 대조
        auto find_result = find(want.begin(), want.end(), test_queue.front());
        if (find_result != want.end())
        {
            // 찾았을 경우
            int index = find_result - want.begin();

            clone_number[index] -= 1;

            test_queue.pop_back();

            if (clone_number[index] < 0)
            {
                start_index++;
                break;
            }
            else if (accumulate(clone_number.begin(), clone_number.end(), 0) == 0)
            {
                start_index++;
                answer++;
                break;  
            }
        }
        else
        {
            // 없는 경우

            start_index++;

            test_queue.pop_back();
            break;
        }
    }

    if (discount.size() - total_index < start_index)
    {
        break;
    }
}
    
    return answer;
}