#include <bits/stdc++.h>

using namespace std;

int t, a, b;

int main(){
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);

    cin >> t >> a >> b;

    vector<vector<bool>> dp(t + 1, vector<bool>(2));

    dp[0][0] = true;

    for(int i = 0; i <= t; i++){
        if(i - a >= 0){
            dp[i][0] = dp[i][0] || dp[i - a][0];
        }
        if(i - b >= 0){
            dp[i][0] = dp[i][0] || dp[i - b][0];
        }

        dp[i/2][1] = dp[i/2][1] || dp[i][0];
    }
    for(int i = 0; i <= t; i++){
        if(i - a >= 0){
            dp[i][1] = dp[i][1] || dp[i - a][1];
        }
        if(i - b >= 0){
            dp[i][1] = dp[i][1] || dp[i - b][1];
        }
    }

    for(int i = t; i >= 0; i--){
        if(dp[i][0] || dp[i][1]){
            cout << i << '\n';
            return 0;
        }
    }
}