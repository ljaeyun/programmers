#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool CheckCondi(char condi, int num, int diff)
{
    if (condi == '=')
    {
        return num == diff;
    }
    else if (condi == '>')
    {
        return diff > num;
    }
    else
    {
        return diff < num;
    }
}


int solution(int n, vector<string> data) {
    int answer = 0;
    
    vector<char> names;
    names.push_back('A');
    names.push_back('C');
    names.push_back('F');
    names.push_back('J');
    names.push_back('M');
    names.push_back('N');
    names.push_back('R');
    names.push_back('T');
    //char names[8] = {'A','C','F','J','M','N','R','T'};

    vector<bool> temp_bool(names.size(), true);

    do {
        // 조건 확인해서 배치 여부 판단
        bool isOK = true;

        for (int i = 0; i < data.size(); i++)
        {
            int firstIndex = find(names.begin(), names.end(), data[i][0]) - names.begin();//find(names, names.size() + 8, [i]) - names;
            int secondIndex = find(names.begin(), names.end(), data[i][2]) - names.begin();

            char condi = data[i][3];
            int condiValue3 = data[i][4] - '0';

            int absValue = abs(firstIndex - secondIndex) - 1;


            if(CheckCondi(condi, condiValue3, absValue))
                continue;

            isOK = false;
            break;            
        }

        if (isOK)
        {
            answer++;
        }

    } while (next_permutation(names.begin(), names.end()));
    
    return answer;
}