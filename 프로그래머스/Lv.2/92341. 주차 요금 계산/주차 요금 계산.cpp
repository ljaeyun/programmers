#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <math.h>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    int stan_time = fees[0];
    int stan_fee = fees[1];
    int plus_time = fees[2];
    int plus_fee = fees[3];

    map<string, int> result;

    map<string, int> car;

    

    for (auto& s : records)
    {
        istringstream ss(s);
        string time;
        string carNumber;
        string status;

        ss >> time >> carNumber >> status;
        int hour = stoi( time.substr(0, 2));
        int min = stoi( time.substr(3, 2));


        //cout << carNumber <<" " << hour << " " << min << endl;
        
        if (status == "IN")
        {
            if (car.find(carNumber) != car.end()) // 
            {
                car.erase(carNumber);
                car.insert({ carNumber, hour * 60 + min });
            }
            else
            {
                car.insert({ carNumber, hour * 60 + min });
            }
            
        }
        else if (status == "OUT")
        {
            if (car.find(carNumber) != car.end())
            {
                
                if (result.find(carNumber) != result.end()) // 값이 지워지지 않고 합쳐지도록 
                {
                    int temp = abs((hour*60+min) - car.find(carNumber)->second) + abs(result.find(carNumber)->second);
                    result.erase(carNumber);
                    result.insert({ carNumber, temp });
                    car.erase(carNumber);
                }
                else
                {
                    result.insert({ carNumber, car.find(carNumber)->second - ((hour * 60) + min) }); 

                    car.erase(carNumber);
                }
            }
        }
        
        if (s == records[records.size()-1] && car.size() != 0)
        {
            for (auto& c : car)
            {
                //int result_value = !result.empty() ? abs(result.find(c.first)->second) : 0;
                int result_value = result.find(c.first) == result.end() ? 0 : abs(result.find(c.first)->second);
                int temp = abs(23 * 60 + 59) - c.second + result_value;
                result.erase(c.first);
                result.insert({ c.first, temp });
                car.erase(c.first);

                if (car.empty())
                    break;
            }
        }
    }

    for (auto& r : result)
    {
        int fee=0;
        if (abs( r.second )> stan_time)
        {
            double temp =ceil((double( abs(r.second)) - double( stan_time)) /  double(plus_time));
            fee += stan_fee +temp * plus_fee;
        }
        else
        {
                fee = stan_fee;
        }

        //answer.insert({ r.first, fee });
        answer.push_back(fee);
    }
    
    return answer;
}