#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 0, leng = a.size();
    int lmnm = a[0], rmnm = a[leng-1];
    
    for(int i = 1; i < leng-1; i++)
    {
        if(lmnm > a[i])
        {
            answer++;
            lmnm = a[i];
        }
        if(rmnm > a[leng-1-i])
        {
            answer++;
            rmnm = a[leng-1-i];
        }
    }
    
    return lmnm == rmnm ? answer+1 : answer+2;
}