#include <string>
#include <vector>
#include <unordered_map>
#include <iterator>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> m;
    unordered_map<string,int>::iterator iter;
    
    for(int i = 0; i < participant.size(); i++)
    {
        if(!m[participant[i]])
            m[participant[i]] = 1;
        else m[participant[i]]++;
    }
    
    for(int i = 0; i < completion.size(); i++)
    {
        m[completion[i]]--;
    }
    
    for(iter = m.begin(); iter != m.end(); iter++)
    {
        if(iter->second){
            answer = iter->first;
            break;
        }
    }
    
    return answer;
}