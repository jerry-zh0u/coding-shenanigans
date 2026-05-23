#include <bits/stdc++.h>

using namespace std;

constexpr int MAXDIST = 2e5 + 1;

int t;

int main(){
    cin >> t;

    for(int tests = 0; tests < t; tests++){
        int n, m;
        cin >> n >> m;

        vector<int> connections[n];
        vector<pair<int, int>> dist(n);
        int dp[n][2];

        for(int i = 0; i < n; i++){
            dist[i].first = i;
            dist[i].second = -1;

            dp[i][1] = MAXDIST;
        }

        dist[0].second = 0;
        dp[0][0] = dp[0][1] = 0;

        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            a--; b--;
            
            connections[a].push_back(b);
        }

        queue<pair<int, int>> cur;
        cur.push({0, 0});

        while(!cur.empty()){
            pair<int, int> temp = cur.front();
            cur.pop();

            for(int e : connections[temp.first]){
                if(dist[e].second != -1){
                    continue;
                }
                dp[e][0] = dp[e][1] = temp.second + 1;
                dist[e].second = temp.second + 1;
                cur.push(make_pair(e, temp.second + 1));
            }
        }

        sort(dist.begin(), dist.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });
        
        for(int i = 0; i < dist.size(); i++){
            int node = dist[i].first;
            for(int e : connections[node]){
                if(dp[e][0] > dp[node][0]){
                    dp[node][1] = min(dp[node][1], dp[e][1]);
                }else{
                    dp[node][1] = min(dp[node][1], dp[e][0]);
                }
            }
        }

        for(int i = 0; i < n; i ++){
            cout << dp[i][1] << " ";
        }
        cout << '\n';
    }
}