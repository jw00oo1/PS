#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    
    for(int i = 0; i < progresses.size(); i++)
    {
          //this can be changed below:
          // day = (99 - progresses[i]) / speeds[i] + 1;
          // days.push_back(day);
        
        int rest = 100 - progresses[i];
        int day = 0, speed = speeds[i];
        if(rest % speed)
        {
            day = rest / speed + 1;
        }
        else day = rest / speed;

        days.push_back(day);
    }

    int mxm = days[0], cnt = 0;
    for(int i = 0; i < days.size(); i++)
    {
        if(mxm >= days[i])
        {
            cnt++;
        }
        else
        {
            mxm = days[i];
            answer.push_back(cnt);
            cnt = 1;
        }
    }
    answer.push_back(cnt);

    return answer;
}
