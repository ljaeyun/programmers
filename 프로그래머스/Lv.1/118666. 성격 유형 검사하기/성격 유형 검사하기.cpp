#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    int newScore[7] = { 3,2,1,0,1,2,3 };
	map<char, int > test;

	int temp = 0;

	test.insert({ 'R', temp});
	test.insert({ 'T', temp });
	test.insert({ 'C', temp });
	test.insert({ 'F', temp });
	test.insert({ 'J', temp });
	test.insert({ 'M', temp });
	test.insert({ 'A', temp });
	test.insert({ 'N', temp });
    
    for (int i = 0; i < survey.size(); i++)
	{
		// 응답 char
		char first_ch = survey.at(i).at(0);
		char last_ch = survey.at(i).at(1);

		int choiceNum = choices.at(i);
		int score = newScore[choiceNum-1];


		//test.insert({ first_ch, temp });
		if (choiceNum > 4)
		{
			test[last_ch] += score;
		}
		else if (choiceNum == 4)
		{

		}
		else if(choiceNum < 4)
		{
			test[first_ch] += score;
		}
	}
    if (test['R'] > test['T'])
	{
		answer.push_back('R');
	}
	else if (test['R'] == test['T'])
	{
		answer.push_back('R');
	}
	else
	{
		answer.push_back('T');
	}
	// ==
	if (test['C'] > test['F'])
	{
		answer.push_back('C');
	}
	else if (test['C'] == test['F'])
	{
		answer.push_back('C');
	}
	else
	{
		answer.push_back('F');
	}
	// ==
	if (test['J'] > test['M'])
	{
		answer.push_back('J');
	}
	else if (test['J'] == test['M'])
	{
		answer.push_back('J');
	}
	else
	{
		answer.push_back('M');
	}
	// ==
	if (test['A'] > test['N'])
	{
		answer.push_back('A');
	}
	else if (test['A'] == test['N'])
	{
		answer.push_back('A');
	}
	else
	{
		answer.push_back('N');
	}
    
    
    
    return answer;
}