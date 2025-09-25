#include <iostream>
using namespace std; 

long long dp[1000002];

int main(void) {
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    #ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin); 
    freopen("./output.txt", "w", stdout); 
    #endif

    int n;
    cin >> n;
    int input[1000002];  
    int max = 0;
    for(int i = 0;i<n;i++) {
        cin >> input[i]; 
        if(max<input[i]) max = input[i]; 
    }

    dp[1] = 1; 
    dp[2] = 2; 
    dp[3] = 4; 

    for(int i = 4; i<=max; i++) {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) %1000000009;
    }

    for(int i = 0;i<n;i++)  cout << dp[input[i]]%1000000009<<'\n'; 

    return 0;
}
