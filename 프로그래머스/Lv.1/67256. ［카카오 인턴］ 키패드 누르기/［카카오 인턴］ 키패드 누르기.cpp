#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    vector<int> leftNum = { 1,4,7 };
    vector<int> rightNum = { 3,6, 9 };
    vector<int> centerNum = { 2, 5 ,8, 0 };
    int x_1 = 0;
    int x = 3; // 초기 위치 
    
    int y_1 = 2;
    int y = 3;
    string hands = hand =="right"? "R" : "L";
    for (auto& in : numbers)
    {
        
        if (find(leftNum.begin(), leftNum.end(), in) != leftNum.end())
        {
            //cout << "왼" << in << endl;;
            answer += "L";
            x = find(leftNum.begin(), leftNum.end(), in) - leftNum.begin();
            x_1 = 0;
        }

        if (find(rightNum.begin(), rightNum.end(), in) != rightNum.end())
        {
            //cout << "오" << in << endl;
            answer += "R";
            y = find(rightNum.begin(), rightNum.end(), in) - rightNum.begin();
            y_1 = 2;
        }
        
        if (find(centerNum.begin(), centerNum.end(), in) != centerNum.end())
        {
            //cout << "중앙" << in << endl;
            int center_1 =1;
            int center = find(centerNum.begin(), centerNum.end(), in) - centerNum.begin();
            //int leftMinus = abs(center - x);
            //int rightMinus = abs(center - y);
            
            int leftMinus = abs(center_1 - x_1) + abs(center - x);
            int rightMinus = abs(center_1 - y_1) + abs(center - y);
            
            if (leftMinus > rightMinus)
            {
                //cout << "오" << in << endl;
                answer += "R";
                y = center;
                y_1 = center_1;
            }
            else if (leftMinus < rightMinus)
            {
                //cout << "왼" << in << endl;
                answer += "L";
                x = center;
                x_1 = center_1;
            }
            else if(leftMinus == rightMinus)
            {
                //cout << "중" << in << endl;
                answer += hands;
                if(hands == "R")
                {
                    y = center;    
                    y_1 = center_1;
                }
                else
                {
                    x = center;
                    x_1 = center_1;    
                }
                
            }
        }
        
    }
    
    
    return answer;
}