#include <bits/stdc++.h>

#define ll long long

using namespace std;

int s, n;

int main(){
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> s >> n;

    vector<vector<ll>> info(n, vector<ll>(3));
    vector<vector<ll>> weights[s + 1];
    vector<vector<ll>> dp(s + 1, vector<ll>(s + 1));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> info[i][j];
        }
    }

    for(vector<ll> e : info){
        if(e[1] > s){
            continue;
        }
        weights[e[1]].push_back({e[0], e[1], e[2]});
    }

    for(int i = 0; i <= s; i++){
        sort(weights[i].begin(), weights[i].end(), [](vector<ll> a, vector<ll> b){
            return a[0] > b[0];
        });
    }


    //stuck on implementation, i feel like it has to be exactly the while loop, i had basically an s^3 before
    for(int i = 1; i <= s; i++){ //current weight being used
        for(int j = 1; j <= s; j++){
            dp[i][j] = dp[i - 1][j];

            int curWeight = j;
            int curMoney = 0;
            for(int k = 0; k < weights[i].size(); k++){
                int copies = 0;
                while(curWeight - i >= 0 && copies < weights[i][k][2]){
                    copies ++;
                    curWeight -= i;
                    curMoney += weights[i][k][0];
                    dp[i][j] = max(dp[i][j], dp[i - 1][curWeight] + curMoney);
                }
                if(curWeight - i < 0){
                    break;
                }
            }
        }

        // int idx = 0;
        // for(int j = 1; j <= s && idx < weights[i].size(); j++){
        //     if(j % i == 0){
        //         dp[j] = max(dp[j], dp[j - i] + weights[i][idx][0]);
        //         weights[i][idx][2]--;
        //         if(weights[i][idx][2] == 0){
        //             idx++;
        //         }
        //     }
        // }
        // for(int j = 0; j <= i; j++){
        //     int curWeight = i;
        //     int curSum = 0;
        //     for(vector<ll> e : weights[j]){
        //         if(curWeight - j * e[2] < 0){
        //             curSum += curWeight/j * e[0];
        //             dp[i] = max(dp[i], dp[curWeight - curWeight/j * j] + curSum);
        //             break;
        //         }else{
        //             curSum += e[0] * e[2];
        //             dp[i] = max(dp[i], dp[curWeight - j * e[2]] + curSum);
        //             curWeight -= j * e[2];
        //         }
        //     }
        // }
        // for(int j = 0; j <= s; j++){
        //     cout << dp[j] << " ";
        // }
        // cout << " ====== "<< '\n';
    }
    ll ret = 0;
    for(int i = 1; i <= s; i++){
        ret = max(ret, dp[s][i]);
    }
    
    cout << ret << '\n';
}