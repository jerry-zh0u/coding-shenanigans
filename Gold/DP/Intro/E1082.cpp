#include <bits/stdc++.h>

constexpr int MAX = 5e5;
int dp[MAX + 1];

int main() {
    int n, c;
    std::cin >> n >> c;

    int numC = 0;
    int bestSub = 0;
    
    for(int i = 0; i < n; i++){
        int a;
        std::cin >> a;

        if(a == c){
            numC++;
        }else{
            dp[a] = std::max(dp[a], numC) + 1;
        }

        bestSub = std::max(bestSub, dp[a] - numC);
    }

    std::cout << numC + bestSub << '\n';
}