#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

int n, x;


int main(){
    cin >> n >> x;

    vector<int> dp(x + 1);
    dp[0] = 1;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;

        for(int j = a; j <= x; j++){
            dp[j] = (dp[j] + dp[j - a]) % MOD;
        }
    }

    cout << dp[x] << '\n';
}