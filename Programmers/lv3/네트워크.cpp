#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int networks = 0;
    int arr[200] = {0};
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(!arr[i]){
            networks++;
            q.push(i);
            while(!q.empty()){
                int tmp = q.front();
                arr[tmp] = networks;
                for(int j = 0; j < computers[tmp].size(); j++){
                    if(computers[tmp][j] && !arr[j])
                        q.push(j);
                }
                q.pop();
            }
        }
    }
    return networks;
}