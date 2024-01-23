using namespace std;

long long solution(int w,int h) {
    long long answer = 1;
        
    
    long long x = (long long)w;
    long long y = (long long)h;
    long long temp;

    if(w != h)
    {
        while (y != 0)
        {
            temp = x % y;
            x = y;
            y = temp;
        }

        long long gcd = x;

        answer = (long long)w * (long long)h - ((long long)w + (long long)h - gcd);
    }
    else
    {
        answer = (long long)w * (long long)h - (long long)w;
    }
    return answer;
}