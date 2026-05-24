//Copied from USACO Guide Editorial: https://usaco.guide/problems/usaco-1185-drought/solution

#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 +7;
constexpr int MAXHUNGER = 1000;

int n;

long long waysOffset(int shift, vector<int> &h, vector<long long> &dp, vector<long long> &diff){
    for(int i = 0; i <= MAXHUNGER; i++){
        dp[i] = 1;
    }

    for(int i = 1; i < n; i++){
        int j = 0;
        while(j <= (h[i - 1] - shift) && (h[i] - shift) - j + 1 >= 0){
            int rb = (h[i] - shift) - j + 1;

            diff[0] += dp[j];

            if(diff[0] >= MOD){
                diff[0] -= MOD;
            }

            diff[rb] = (((diff[rb] - dp[j]) % MOD) + MOD) % MOD;
            j++;
        }

        dp[0] = diff[0]; //initializing your dp array, this becomes your like new coloumn

        for(int j = 1; j <= MAXHUNGER; j++){
            dp[j] = dp[j - 1] + diff[j];

            if(dp[j] >= MOD){
                dp[j] -= MOD;
            }
        }

        for(int j = 0; j <= MAXHUNGER; j++){
            diff[j] = 0;
        }
    }

    return dp[0];
}

int main(){
    cin >> n;
    vector<int> heights(n);
    vector<long long> dp(MAXHUNGER + 1);
    vector<long long> diff(MAXHUNGER + 2);

    int mn = MAXHUNGER;
    for(int i = 0; i < n; i++){
        cin >> heights[i];
        mn = min(mn, heights[i]);
    }

    long long ans = 0;
    
    if(n % 2 == 1){
        for(int i = 0; i <= mn; i++){
            ans = (ans + waysOffset(i, heights, dp, diff) + MOD) % MOD;
        }
    }else{
        ans = (ans + waysOffset(0, heights, dp, diff) + MOD) % MOD;
    }

    cout << ans << '\n';
}