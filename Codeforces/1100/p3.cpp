#include <bits/stdc++.h>

using namespace std;

int main(){    
    int t;
    cin >> t;

    for(int tests = 0; tests < t; tests++){
        int n;
        cin >> n;

        int nums[n];
        int count = 0;
        string ans = "";
        stack<int> cur;

        for(int i = 0; i < n; i++){
            cin >> nums[i];

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
        if(nums[n - 1] > 0){
            cur.push(n - 1);
        }
        while(!cur.empty()){
            int big = cur.top() + 1;
            cur.pop();

            count ++;
            ans += to_string(big) + " ";
        }
        cout << count << '\n';
        cout << ans << '\n';
    }
}