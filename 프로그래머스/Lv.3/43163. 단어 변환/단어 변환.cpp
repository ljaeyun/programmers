#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool checkWord(string a, string b)
{
    int diffCount = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            diffCount++;
            if (diffCount > 1)
                break;
        }
    }

    if (diffCount == 1)
        return true;
    else
        return false;
}

int wordDfs(string begin, string target, vector<string> words, vector<bool> isChecked, int count, int answer)
{
    if (begin == target)
        return count - 1;

    for (int i = 0; i < words.size(); i++)
    {
        if (checkWord(begin, words[i]) && !isChecked[i])
        {
            isChecked[i] = true;
            answer = min(answer, wordDfs(words[i], target, words, isChecked, count + 1, answer));
            isChecked[i] = false;
        }
    }

    return answer;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 50;
    
    vector<bool> isChecked(words.size(), false);

queue<string> q;

// target이 words 안에 있는 경우
if (find(words.begin(), words.end(), target) != words.end())
{
    answer = wordDfs(begin, target, words, isChecked, 1, answer);

}
else
{
    // 없는 경우
    answer = 0;
}
    
    return answer;
}