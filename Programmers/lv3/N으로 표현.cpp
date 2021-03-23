#include <string>
#include <unordered_set>
#define abs(a) (a<0?-(a):a)
using namespace std;

int solution(int N, int number) {
    unordered_set<int> m[9];

    int answer, tmp = 0;

    for(answer = 1; answer <= 8; answer++)
    {
        tmp = tmp*10 + N;
        m[answer].insert(tmp);
        
        for(int j = 1; j <= answer/2; j++)
        {
            for(int n1 : m[j])
            {
                for(int n2 : m[answer-j])
                {   
                    m[answer].insert(n1 + n2);
                    m[answer].insert(abs(n1-n2));
                    m[answer].insert(n1*n2);
                    if(n1) m[answer].insert(n2/n1);
                    if(n2) m[answer].insert(n1/n2);
                }
            }
        }
        if(m[answer].find(number) != m[answer].end())
            return answer;
    }
    return -1;
}