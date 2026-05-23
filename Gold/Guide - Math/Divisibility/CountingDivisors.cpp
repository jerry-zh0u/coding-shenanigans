#include <iostream>

using namespace std;

const int MAX_N = 1e6;

int maxDiv[MAX_N + 1];

int main(){
    for(int i = 2; i <= MAX_N; i++){
        if(maxDiv[i] == 0){
            for(int j = i ; j <= MAX_N ; j+=i){
                maxDiv[j] = i;
            }
        }
    }

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        int divAmt = 1;

        while (x != 1){
            int prime = maxDiv[x];

            int count = 0;
            while(x % prime == 0){
                x /= prime;
                count += 1;
            }
            divAmt *= (count + 1);
        }
        cout << divAmt << '\n';
    }
}