#include <iostream>
using namespace std; 

int arr[1001]; 
int dp[1001]; 

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    int n;
    cin >> n;

    for(int i =0;i<n;i++){
        cin >> arr[i]; 
    }

    fill(dp, dp+n, 1); 
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<i;j++) {
            if(arr[i]>arr[j]) dp[i] = dp[i]>dp[j]+1?dp[i]: dp[j]+1; 
        }
    }
    
    int result = 0; 
    for(int i = 0;i<n;i++) result<dp[i]?result = dp[i]: result = result; 
    cout << result; 
    return 0;
}