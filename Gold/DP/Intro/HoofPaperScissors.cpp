#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 1;
constexpr int MAXK = 20 + 1;
constexpr int MAXCHOICE = 3;

int dp[MAXN][MAXK][MAXCHOICE]; // 0 = Hoof, 1 = Paper, 2 = Scissor

int main(){
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        char c;
        cin >> c;
        
        for(int j = 0; j < 3; j++){
            dp[i][0][j] = dp[i - 1][0][j];
        }
        if(c == 'H'){
            dp[i][0][1] ++;
        }else if(c == 'P'){
            dp[i][0][2] ++;
        }else{
            dp[i][0][0] ++;
        }
        for(int j = 1; j <= k; j++){
            dp[i][j][0] = dp[i - 1][j][0];
            dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - 1][1]);
            dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - 1][2]);

            dp[i][j][1] = dp[i - 1][j][1];
            dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][0]);
            dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][2]);

            dp[i][j][2] = dp[i - 1][j][2];
            dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j - 1][0]);
            dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j - 1][1]);

            if(c == 'H'){
                dp[i][j][1] ++;
            }else if(c == 'P'){
                dp[i][j][2] ++;
            }else{
                dp[i][j][0] ++;
            }
        }
    }

    int ret = 0;
    for(int i = 0; i < 3; i ++){
        ret = max(ret, dp[n][k][i]);
    }
    cout << ret << '\n';
}