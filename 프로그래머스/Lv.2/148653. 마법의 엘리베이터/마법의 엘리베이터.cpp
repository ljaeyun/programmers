#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while (storey != 0)
{
    int temp = storey % 10;

      if (temp <= 4)
 {
     storey -= temp;
     answer += temp;
 }
 else if (temp > 5)
 {
     storey += (10-temp);
     answer += (10 - temp);
 }
 else 
 {
     if (storey / 10 % 10 >= 5)
     {
         storey += (10 - temp);
         answer += (10 - temp);
     }
     else
     {
         storey -= temp;
         answer += temp;
     }
 }


    storey /= 10;
    

    if (storey == 0)
        break;  
}
    
    return answer;
}