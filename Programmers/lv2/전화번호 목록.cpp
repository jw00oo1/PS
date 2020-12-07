#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool strstr(string a, string b){
    bool result = true;
    string shorter = (a.size() <= b.size() ? a : b);
    string longer = (a.size() <= b.size() ? b : a);

    for(int i = 0; i < shorter.size(); i++){
        if(shorter[i] != longer[i]){
            result = false;
            break;
        }
    }
    return result;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    bool chk = false;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i < phone_book.size()-1; i++){
        chk = strstr(phone_book[i], phone_book[i+1]);
        if(chk){
            answer = false;
            break;
        }
    }
    
    return answer;
}