#include <bits/stdc++.h>

using namespace std;

constexpr long long INF = 1e18;

int n, k;

int main(){
    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);

    cin >> n >> k;

    vector<int> barns(n);
    long long ret = INF;

    for(int i = 0; i < n; i++){
        cin >> barns[i];
    }

    for(int i = 0; i < n; i++){
        int offset = i;
        long long dp[n][k + 1][2]; // 0 you are a door, 1 you are not a door
        for(int j = 0; j < n; j++){
            for(int l = 0; l <= k; l++){
                dp[j][l][0] = dp[j][l][1] = INF;
            }
        }
        dp[0][1][0] = 0;

        for(int j = 1; j < n; j++){
            for(int l = 1; l <= k; l++){
                dp[j][l][0] = min(dp[j - 1][l - 1][1], dp[j - 1][l - 1][0]);
                
                long long dist = 0;
                long long cows = barns[(j + offset) % n];
                for(int m = j - 1; m >= 0; m--){
                    dist += cows;
                    dp[j][l][1] = min(dp[j][l][1], dp[m][l][0] + dist);
                    cows += barns[(m + offset) % n];
                }
            }
        }
        ret = min(ret, min(dp[n - 1][k][0], dp[n - 1][k][1]));
    }

    cout << ret << '\n';
}