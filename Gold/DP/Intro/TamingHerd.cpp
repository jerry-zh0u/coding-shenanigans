#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 1e6;
int n;

int main(){
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);

    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int dp[n + 1][n + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = MAX;
        }
    }

    dp[n][0] = 0;

    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j <= n; j++){ //number of gates you ahve
            int bad = 0;
            for(int k = i; k < n; k++){
                if(nums[k] != k - i){
                    bad++;
                }
                //start of a breakout
                dp[i][j] = min(dp[i][j], bad + dp[k + 1][j - 1]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << dp[0][i] << '\n';
    }
}   