#include <bits/stdc++.h>

using namespace std;

int n, k;

int main(){
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);

    cin >> n >> k;

    vector<int> nums(n);
    vector<int> dp(n + 1);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    for(int i = 1; i <= n; i++){
        int ret = nums[i - 1];
        dp[i] = dp[i - 1] + ret;
        for(int j = i - 1; j > max(0, i - k); j--){
            ret = max(ret, nums[j - 1]);
            dp[i] = max(dp[i], dp[j - 1] + ret * (i - j + 1));
        }
    }
    cout << dp[n] << '\n';
}