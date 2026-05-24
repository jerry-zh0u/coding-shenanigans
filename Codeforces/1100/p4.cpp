#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);

    int t;
    cin >> t;


    for(int tests = 0; tests < t; tests++){
        int n;
        cin >> n;

        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }

        int idx = -1;
        int diff = 0;
        int sum = -nums[0];

        for(int i = 1; i < n; i++){
            if(nums[i] > 0){
                if(sum - nums[i] > diff){
                    diff = sum - nums[i];
                    idx = i;
                }
            }
            sum += -nums[i];
        }

        if(idx == -1){
            cout << 0 << '\n';
            cout << '\n';
            continue;
        }

        int count = 0;
        string ans = "";
        stack<int> cur;

        // cout << idx << " ====" << ans << '\n';

        for(int i = 0; i < idx; i++){
            if(i == 0){
                continue;
            }else{
                if(nums[i] < 0 && nums[i - 1] > 0){
                    cur.push(i - 1);
                }else if(nums[i] > 0 && nums[i - 1] < 0){
                    cur.push(i - 1);
                }
            }
        }
        if(nums[idx - 1] > 0){
            cur.push(idx - 1);
        }
        while(!cur.empty()){
            int big = cur.top() + 1;
            // cout << big << " === " << '\n';
            cur.pop();

            count ++;
            ans += to_string(big) + " ";
        }
        count += 1;
        ans += to_string(idx + 1);
        cout << count << '\n';
        cout << ans << '\n';
    }
}