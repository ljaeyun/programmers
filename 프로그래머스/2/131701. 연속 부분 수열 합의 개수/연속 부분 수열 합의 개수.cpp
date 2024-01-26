#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    
    set<int> set_elements;
    
    for(int i = 0 ; i < elements.size() ; i++)
    {
        int sum = 0;
        for(int j = 0 ; j < elements.size(); j++)
        {
            int new_index = 0;
            if(i + j >= elements.size())
            {
                new_index = (i + j) % elements.size();
            }
            else
            {
                new_index = i + j;
            }
            
            sum += elements[new_index];
            
            set_elements.insert(sum);
        }
    }
    
    answer = set_elements.size();
    return answer;
}