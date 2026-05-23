#include <bits/stdc++.h>

using namespace std;

constexpr int MAXSIZE = 1e9;

int n, k;

int main(){
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);

    cin >> n >> k;

    int dp[k + 2][n + 1];
    int nums[n];

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    for(int i = 0; i <= k + 1; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = MAXSIZE;
        }
    }
    dp[0][0] = 0;

    for(int i = 1; i <= n; i++){
        int curMax = nums[i - 1];
        int sum = 0;
        for(int j = i; j > 0; j--){
            curMax = max(curMax, nums[j - 1]);
            sum += nums[j - 1];
            // cout << curMax << " " << (j - i + 1) << " " << sum << '\n';
            for(int l = 1; l <= k + 1; l++){
                dp[l][i] = min(dp[l][i], dp[l - 1][j - 1] + curMax * (i - j + 1) - sum);
            }
        }
    }

    // for (int i = 0; i <= k + 1; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << dp[k + 1][n] << '\n';
}