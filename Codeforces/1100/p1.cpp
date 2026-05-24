#include <bits/stdc++.h>

using namespace std;

int main(){
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    
    int t;
    cin >> t;

    for(int tests = 0; tests < t; tests++){
        int n;
        cin >> n;
        
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }

        int avg = (*max_element(nums.begin(), nums.end()) + *min_element(nums.begin(), nums.end()))/2;
        int ans = 0;

        for(int i = 0; i < n; i++){
            ans = max(ans, abs(avg - nums[i]));
        }
        cout << ans << '\n';
    }
}