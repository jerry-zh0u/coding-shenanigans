#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 9;

int n, m, k;

int main(){
    freopen("team.in", "r", stdin);
    freopen("team.out", "w", stdout);

    cin >> n >> m >> k;

    vector<int> john(n);
    vector<int> paul(m);
    
    long long dp[n + 1][m + 1][k + 1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            for(int l = 0; l <= k; l++){
                dp[i][j][l] = 0;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cin >> john[i];
    }
    for(int i = 0; i < m; i++){
        cin >> paul[i];
    }

    sort(john.begin(), john.end());
    sort(paul.begin(), paul.end());

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j][0] = 1;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int l = 1; l <= k; l++){
                dp[i][j][l] += dp[i][j - 1][l];
                dp[i][j][l] += dp[i - 1][j][l];
                dp[i][j][l] -= dp[i - 1][j - 1][l];

                if(john[i - 1] > paul[j - 1]){
                    dp[i][j][l] += dp[i - 1][j - 1][l - 1];
                }

                dp[i][j][l] += MOD;
                dp[i][j][l] %= MOD;
            }
        }
    }

    cout << dp[n][m][k] << '\n';
}