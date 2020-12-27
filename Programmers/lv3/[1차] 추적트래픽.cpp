#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector<float> start;
    vector<float> end;

    //시간 처리
    for(int i = 0; i < lines.size(); i++)
    {
        int hour = stoi(lines[i].substr(11, 2)), min = stoi(lines[i].substr(14,2));
        float sec = stof(lines[i].substr(17,6)), during = stof(lines[i].substr(24,5));
        float e_time = hour * 3600 + min * 60 + sec;
        float s_time = e_time - during + 0.001;

        start.push_back(s_time);
        end.push_back(e_time);
    }

    sort(start.begin(), start.end());

    for(int i = 0; i < end.size(); i++)
    {
        int cnt = 0;
        float target = end[i] + 1;
        for(int j = i; j < start.size(); j++)
        {
            if(start[j] < target)
                cnt++;
            else break;
        }
        answer = (answer < cnt)? cnt : answer;
    }

    return answer;
}