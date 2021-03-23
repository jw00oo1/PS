#include <string>
#include <vector>
#include <algorithm>
#define INF 9876543210

using namespace std;

int solution(vector<int> a) {
    int answer = 1;
    int lmnm = a[0], mnm = INF, target, rmnm;
    vector<int> rmnm_list;
    
    for(int i = a.size()-1; i > 0; i--)
    {
        rmnm_list.push_back(mnm);
        if(mnm > a[i])
            mnm = a[i];
    }
    
    int leng = rmnm_list.size();
    
    for(int i = 1; i < a.size()-1; i++)
    {
        target = a[i];
        rmnm = rmnm_list[leng - i];
        //cmp
        if(lmnm >= target || rmnm >= target)
            answer++;
        
        if(lmnm >= target)
            lmnm = target;
    }
    if(a.size() > 1)
        answer++;
    
    return answer;
}