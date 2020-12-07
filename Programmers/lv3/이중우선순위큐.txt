#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int total = 0;
    priority_queue <int> less, greater;

    for(int i = 0; i < operations.size(); i++)
    {
        string now = operations[i];

        if(now[0] == 'I')
        {
            int s_int = stoi(now.substr(2, now.size()-1));
            less.push(-s_int);
            greater.push(s_int);
            total++;
        }
        else
        {
            if(total)
            {
                if(now[2] != '-')  //delete biggest element
                {
                    if(!greater.empty())
                    {
                        greater.pop();
                    }
                }
                else
                {
                    if(!less.empty())
                    {
                        less.pop();
                    }
                }
                total--;
            }
        }

        if(total == 0)
        {
            greater = priority_queue<int>();
            less = priority_queue<int>();
        }
    }

    if(total == 0)
    {
        answer = {0,0};
    }
    else
    {
        answer.push_back(greater.top());
        answer.push_back(-less.top());
    }

    return answer;
}