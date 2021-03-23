#include <string>
#include <vector>
#define MOD 1000000007

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int dp[101][101] = {0};

    //puddle check
    for(int i = 0; i < puddles.size(); i++)
    {
        int x = puddles[i][0], y = puddles[i][1];
        dp[x][y] = -1;
    }

    dp[0][1] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(dp[j][i] < 0)
                continue;

            int left = (dp[j-1][i] < 0 ? 0 : dp[j-1][i]);
            int up = (dp[j][i-1] < 0 ? 0 : dp[j][i-1]);

            dp[j][i] = (left + up)%MOD;
        }
    }

    answer = dp[m][n]%MOD;

    return answer;
}