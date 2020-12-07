#include <string>
#include <vector>
#define min(a,b)    ((a)<(b)? (a):(b))
#define INF 987654321
using namespace std;

int solution(string name) {
    int answer = 0, leng = name.length();
    for(int i = 0; i < leng; i++){
        char letter = name[i];
        answer += min(letter-'A', 'Z'-letter+1);
    }
    int n_idx, tmp = INF;
    for(int i  = 0; i < leng; i = n_idx){
        n_idx = i+1;
        while(n_idx < leng && name[n_idx]=='A')
            n_idx++;
        if(n_idx < leng)
            tmp = min(tmp, i*2 + leng - n_idx);
        else{
            tmp = min(tmp, i);
            break;
        }
    }
   answer += tmp;
    return answer;
}