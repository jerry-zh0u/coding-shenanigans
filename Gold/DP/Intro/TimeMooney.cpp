#include <bits/stdc++.h>

using namespace std;

constexpr int MAXTIME = 1001;

int n, m, c;


int main(){
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);

    cin >> n >> m >> c;
    
    vector<int> vals(n);
    vector<int> adj[n];
    
    int dp[MAXTIME][n];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    for(int i = 0; i < n; i++){
        cin >> vals[i];
    }

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a -= 1; b -= 1;
        adj[b].push_back(a);
    }

    for(int i = 1; i < MAXTIME; i++){
        for(int j = 0; j < n; j++){
            for(int e : adj[j]){
                if(dp[i - 1][e] == -1){
                    continue;
                }
                dp[i][j] = max(dp[i][j], dp[i - 1][e] + vals[e]);
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < MAXTIME; i++){
        ans = max(ans, dp[i][0] - c * i * i);
    }

    cout << ans << '\n';
}