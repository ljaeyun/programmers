#include <string>
#include <vector>

using namespace std;

// 1
string func1(string id)
{
    string value = "";
    for(int i = 0 ; i < id.size(); i++)
    {
        if(id[i] >= 65 && id[i] <= 90)
        {
            value.push_back(id[i] + 32);
        }
        else
        {
            value.push_back(id[i]);
        }        
    }
    return value;
}

// 2
string func2(string id)
{
    string value = "";
    
    for(int i = 0; i < id.size(); i++)
    {
        if(id[i]>= 97 && id[i] <= 122)
        {
            value.push_back(id[i]);
        }
        else if(id[i] >= 48 && id[i] <= 57)
        {
            value.push_back(id[i]);
        }
        else if(id[i] == '-')
        {
            value.push_back(id[i]);
        }
        else if(id[i] == '_')
        {
            value.push_back(id[i]);
        }
        else if(id[i] == '.')
        {
            value.push_back(id[i]);
        }
    
    }
    
    return value;
}

// 3
string func3(string id)
{
    string value = "";
    
    string dotTemp = "";
    for(int i = 0 ; i < id.size(); i++)
    {
        if(id[i] == '.')
        {
            if(dotTemp.size() == 0)
            {
                value.push_back(id[i]);
                dotTemp.push_back(id[i]);
            }
            else if(dotTemp.size() > 0 && id[i] == '.')
            {
                continue;
            }
            else if(id[i] != '.' && dotTemp.size() > 0)
            {
                dotTemp = "";
                continue;
            }
        }
        else
        {
            value.push_back(id[i]);
            dotTemp = "";
        }            
    }
    
    return value;
}

string func4(string id)
{
    if (id[0] == '.')
    {
        id.erase(0, 1);
    }

    if (id.size() > 0 && id[id.size() - 1] == '.')
    {
        id.erase(id.size() - 1);
    }
    
    return id;
}

string func5(string id)
{
    if(id.size() == 0)
    {
        id.push_back('a');
    }
    
    return id;
}
    
string func6(string id)
{
    if(id.size() > 15)
    {
        id.erase(15, id.size() - 14);
    }
    id = func4(id);
    return id;
}

string func7(string id)
{
    if(id.size() <= 2)
    {
        while(id.size() !=3)
        {
            id.push_back(id[id.size()-1]);
        }
    }
    
    return id;
}

string solution(string new_id) {
    string answer = "";
    //new_id = "dDIID..Kd.ie-+349_...2+$%#___--";
    
    new_id = func1(new_id);
    new_id = func2(new_id);
    new_id = func3(new_id);
    new_id = func4(new_id);
    new_id = func5(new_id);
    new_id = func6(new_id);
    new_id = func7(new_id);
    answer = new_id;
    return answer;
}