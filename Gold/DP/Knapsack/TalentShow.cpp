#include <bits/stdc++.h>

using namespace std;

constexpr long long MAXWEIGHT = 1e6;

int n, w;
int dp[MAXWEIGHT + 1];

int main(){
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);

    cin >> n >> w;

    int ret = 0;
    
    fill(dp, dp + MAXWEIGHT + 1, -1);
    dp[0] = 0;

    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        for(int j = MAXWEIGHT; j >= a; j--) {
            if(dp[j - a] == -1) continue;

            dp[j] = max(dp[j], dp[j - a] + b);

            if(j >= w)
                ret = max(ret, dp[j] * 1000 / j);
        }
    }

    cout << ret << '\n';
}