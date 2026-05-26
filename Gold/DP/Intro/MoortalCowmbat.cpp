#include <bits/stdc++.h>

#define ll long long

using namespace std;

constexpr ll INF = 1e12;

int n, m, k;
string s;

int main(){
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);

    cin >> n >> m >> k;

    cin >> s;

    int dist[m][m];
    ll change[n + 1][m];
    ll dp[n + 1][m];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j < m; j++){
            dp[i][j] = INF;
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            cin >> dist[i][j];
        }
        dp[0][i] = 0;
    }

    for(int l = 0; l < m; l++){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                dist[i][j] = min(dist[i][j], dist[i][l] + dist[l][j]);
            }
        }
    }

    //precompute
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            change[i][j] = dist[s[i - 1] - 'a'][j] + change[i - 1][j];
        }
    }
    
    for(int i = k; i <= n; i ++){
        for(int j = 0; j < m; j++){
            dp[i][j] = dp[i - 1][j] + change[i][j] - change[i - 1][j];
            for(int l = 0; l < m; l++){
                dp[i][j] = min(dp[i][j], dp[i - k][l] + change[i][j] - change[i - k][j]);
            }
        }
    }
    ll ret = dp[n][0];
    for(int i = 0; i < m; i++){
        ret = min(ret, dp[n][i]);
    }

    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    cout << ret << '\n';
}