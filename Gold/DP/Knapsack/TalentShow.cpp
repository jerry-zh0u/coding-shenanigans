#include <bits/stdc++.h>

using namespace std;

constexpr long long INF = 1e12;
constexpr int NMAX = 250;
constexpr int WMAX = 1000;

int n, w;
long long cows[NMAX][2];
long long dp[WMAX + 1];

bool check(int x){
    for(int i = 0; i <= w; i++){
        dp[i] = -INF;
    }
    dp[0] = 0;

    for(int i = 0; i < n; i++){
        long long val = 1000 * cows[i][1] - x * cows[i][0];
        for(int j = w; j >= 0; j--){
            int k = min(w, j + (int)cows[i][0]);

            if(dp[j] != -INF){
                dp[k] = max(dp[k], dp[j] + val);
            }   
        }
    }

    return dp[w] >= 0;
}

int main(){
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);

    cin >> n >> w;

    for(int i = 0; i < n; i++){
        cin >> cows[i][0] >> cows[i][1];
    }

    int left = 0;
    int right = 1000 * 250 * 1000;

    while(left < right){
        int mid = left + (right - left + 1)/2;

        if(check(mid)){
            left = mid;
        }else{
            right = mid - 1;
        }
    }

    cout << left << '\n';
}

//DP cheese possibly?
// #include <bits/stdc++.h>

// using namespace std;

// constexpr long long MAXWEIGHT = 1e6;

// int n, w;
// int dp[MAXWEIGHT + 1];

// int main(){
//     freopen("talent.in", "r", stdin);
//     freopen("talent.out", "w", stdout);

//     cin >> n >> w;

//     int ret = 0;
    
//     fill(dp, dp + MAXWEIGHT + 1, -1);
//     dp[0] = 0;

//     for(int i = 0; i < n; i++) {
//         int a, b;
//         cin >> a >> b;

//         for(int j = MAXWEIGHT; j >= a; j--) {
//             if(dp[j - a] == -1) continue;

//             dp[j] = max(dp[j], dp[j - a] + b);

//             if(j >= w)
//                 ret = max(ret, dp[j] * 1000 / j);
//         }
//     }

//     cout << ret << '\n';
// }