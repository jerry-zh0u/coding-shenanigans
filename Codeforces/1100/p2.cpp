#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    cin >> t;

    for(int tests = 0; tests < t; tests++){
        int n;
        cin >> n;
        long long a[n];
        long long b[n];

        for(int i = 0; i < n; i ++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i ++){
            cin >> b[i];
        }

        long long sum = 0;
        long long maxInA = 0;
        for(int i = 0; i < n; i++){
            int c = max(a[i], b[i]);
            int d = min(a[i], b[i]);
            a[i] = d;
            maxInA = max(maxInA, a[i]);
            b[i] = c;
            sum += c;
        }

        sum += maxInA;

        cout << sum << '\n';
    }
}