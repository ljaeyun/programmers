#include <string>
#include <vector>

using namespace std;

bool IsBigger(vector<int> a, int b, bool is_x)
{
    if (is_x == true)
    {
        if (a[0] > b)
        {
            return true;
        }
    }
    else if (is_x == false)
    {
        if(a[1] > b)
        {
            return true;
        }
    }

    return false;
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    
    // Ax + By + E = 0
// Cx + Dy + F = 0

// AD - BC = 0 인 경우 두직선은 평행 또는 일치
vector<vector<int>> coordinates;

for (int i = 0; i < line.size(); i++)
{
    for (int j = i+1; j < line.size(); j++)
    {        

        if ((long)(line[i][0] * line[j][1]) - (long)(line[i][1] * line[j][0]) == 0)
        {
            // 평행 또는 일치
        }
        else
        {
            // 교점
            vector<int> temp_coord;
            long double temp_x = 0.0;
            long double temp_y = 0.0;

            if (((long)(line[i][0] * line[j][1]) - (long)(line[i][1] * line[j][0])) != 0)
            {

                temp_x = (long double)((line[i][1] * line[j][2]) - (line[j][1] * line[i][2])) / (long double)((line[i][0] * line[j][1]) - (line[j][0] * line[i][1]));
                temp_y = (long double)(((line[i][2] * line[j][0]) - (line[i][0] * line[j][2])) / (long double)((line[i][0] * line[j][1]) - (line[i][1] * line[j][0])));

                if (temp_x - (long)temp_x == 0)
                {
                    temp_coord.push_back(temp_x);
                }

                if (temp_y - (int)temp_y == 0)
                {
                    temp_coord.push_back(temp_y);
                }

                if (!temp_coord.empty() && temp_coord.size() == 2)
                {
                    coordinates.push_back(temp_coord);
                }
            }                
        }
    }
}

    if(coordinates.size() > 0)
    {
        // x, y 의 최대값 저장
        long max_x = coordinates[0][0];
        long max_y = coordinates[0][1];

        long min_x = coordinates[0][0];
        long min_y = coordinates[0][1];

        for (int i = 0; i < coordinates.size(); i++)
        {
            if (IsBigger(coordinates[i], max_x, true))
            {
                max_x = coordinates[i][0];
            }

            if (!IsBigger(coordinates[i], min_x, true))
            {
                min_x = coordinates[i][0];
            }

            if (IsBigger(coordinates[i], max_y, false))
            {
                max_y = coordinates[i][1];
            }

            if (!IsBigger(coordinates[i], min_y, false))
            {
                min_y = coordinates[i][1];
            }
        }

        // 정답
        for (int i = max_y; i >= min_y; i--)
        {
            string str(max_x - min_x + 1, '.');

            for (int j = min_x; j <= max_x; j++)
            {
                bool f = false;
                for (int m = 0; m < coordinates.size(); m++)
                {
                    if (coordinates[m][0] == j && coordinates[m][1] == i)
                        f = true;
                }
                if (f)
                {
                    str[j - min_x] = '*';
                }
            }
            answer.push_back(str);
        }
    }
    else
    {
        answer.push_back("*");
    }
    return answer;
}