#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

bool cmp(const pair<int,int> &a, const pair<int,int> &b)
{
    if(a.first > b.first)   return true;
    else if(a.first == b.first && a.second < b.second)  return true;
    return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string,int> gen_sum;
    unordered_map<string, vector<pair<int,int>>> songs;
    
    for(int i = 0; i < plays.size(); i++)
    {
        gen_sum[genres[i]] += plays[i];
        songs[genres[i]].push_back({plays[i], i});  //plays, idx
    }
    
    vector<pair<int, string>> sorted_gen;
    
    for(auto gen : gen_sum)
        sorted_gen.push_back({gen.second, gen.first});  //sum, genre
    
    sort(sorted_gen.begin(), sorted_gen.end());
    
    for(int i = sorted_gen.size()-1; i >= 0; i--)
    {
        string genre = sorted_gen[i].second;
        sort(songs[genre].begin(), songs[genre].end(),cmp);
        
        int num = (1 < songs[genre].size() ? 2 : 1);
        for(int j = 0; j < num; j++)
        {
            answer.push_back(songs[genre][j].second);
        }
    }
    
    return answer;
}