#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> a) {
    int answer = a.size();
    stack<int> s;
    for(auto element : a)
    {
        while(!s.empty() && element < s.top())
        {
            s.pop();
            if(!s.empty())
                answer--;
        }
        s.push(element);
    }
    return answer;
}

//11.83ms