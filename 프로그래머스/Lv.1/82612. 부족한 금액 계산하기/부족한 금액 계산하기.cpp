using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;

    long long temp = 0;
    for (int i = 1; i <= count; i++)
    {
        temp += price * i;

    }

    answer = temp >= money ? temp - money : 0;
    
    return answer;
}