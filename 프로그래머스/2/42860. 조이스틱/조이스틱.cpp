#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    
    auto alphabet = new char[26] {'A', 'B', 'C', 'D', 'E', 'F', 'G','H','I','J','K','L' ,'M',   'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int n = name.length();
    int turn = name.length() - 1;
    for (int i = 0; i < name.length(); i++)
    {
        int findIndex = distance(alphabet, find(alphabet, alphabet + 26, name[i]));
        if (findIndex < 13)
        {
            answer += findIndex;
        }
        else
        {
            answer += (26 - findIndex);
        }

        int index = i + 1;
        while (index < n && name[index] == 'A')
        {
            index++;
        }

        turn = min(turn, i + n - index + min(i, n - index));
    }
    answer += turn;
    
    return answer;
}