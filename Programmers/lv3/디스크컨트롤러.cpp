#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    priority_queue<pair<int, int>> pq;
    sort(jobs.begin(), jobs.end());
    int now = 0, idx = 0, leng = jobs.size();
    pair<int, int> front;
    pq.push(make_pair(0,0));
    
    while(1){
        for(; idx < leng; idx++){
            if(now > -jobs[idx][0]){
                break;
            }
            pq.push(make_pair(-jobs[idx][1], -jobs[idx][0]));
        }
        
        if(pq.empty())
        {
            if(idx == leng)
                break;
            else{
                pq.push(make_pair(-jobs[idx][1], -jobs[idx][0]));
                now = pq.top().second;
                idx++;
            }
        }
        
        front = pq.top();
        pq.pop();
        answer += (now - front.second + front.first);
        now += front.first;
    }
    
    answer = (-answer) / leng;
    return answer;
}