#include <bits/stdc++.h>

#define ll long long

using namespace std;

constexpr int K = 5e3;
constexpr int MOD = 1e9 + 7;

int n, x;

int main(){
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n >> x;

    vector<int> cows(n);

    for(int i = 0; i < n; i++){
        cin >> cows[i];
    }

    sort(cows.begin(), cows.end());

    vector<vector<ll>> dp1(n + 1, vector<ll> (x + K + 1));
    vector<vector<ll>> dp2(n + 1, vector<ll> (x + K + 1));

    dp1[0][0 + K] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= n - i; j++){
            for(int k = 0; k <= x + K; k++){
                if(!dp1[j][k]){
                    continue;
                }
                dp2[j][k] += dp1[j][k];
                if(j <= n - (i + 1)){
                    dp2[j][k] += j * dp1[j][k];
                }
                if(j + 1 <= n - (i + 1)){
                    dp2[j + 1][k - cows[i]] += dp1[j][k]; 
                }
                if(j && k + cows[i] <= x + K){
                    dp2[j - 1][k + cows[i]] += j * dp1[j][k];
                }
            }
        }

        for(int j = 0; j <= (n - (i + 1)); j++){
            for(int k = 0; k <= x + K; k++){
                dp1[j][k] = dp2[j][k] % MOD;
                dp2[j][k] = 0;
            }
        }
    }

    int ans = 0;
    for(int i = K; i <= x + K; i++){
        ans += dp1[0][i];
        ans %= MOD;
    }

    cout << ans << '\n';
}