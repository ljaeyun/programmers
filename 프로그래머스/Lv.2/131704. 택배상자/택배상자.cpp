#include <string>
#include <vector>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    vector<int> subBelt;
	int orderSize = order.size();
	
	int boxStartNum = 1;
	int index = 0;
	while (boxStartNum <= orderSize)
	{
		subBelt.push_back(boxStartNum++);

		while (subBelt.back() == order[index])
		{
			answer++;
			index++;
			subBelt.pop_back();
			if (subBelt.size() == 0)
				break;
		}
	}
    
    return answer;
}