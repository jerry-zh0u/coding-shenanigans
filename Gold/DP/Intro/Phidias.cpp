#include <bits/stdc++.h>

using namespace std;

int w, h;
int n;

int main(){
    cin >> w >> h;
    cin >> n;

    int rects[n][2];
    int dp[w + 1][h + 1];

    for(int i = 0; i <= w; i++){
        for(int j = 0; j <= h; j++){
            dp[i][j] = i * j;
        }
    }
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        dp[a][b] = 0;
    }


    for(int i = 1; i <= w; i++){
        for(int j = 1; j <= h; j++){
            //fix the i
            for(int k = 1; k <= j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k]);
            }

            //fix the j
            for(int k = 1; k <= i; k++){
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j]);
            }
        }
    }
    cout << dp[w][h] << '\n';
}