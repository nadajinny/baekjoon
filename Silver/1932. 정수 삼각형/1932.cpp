#include <iostream>
using namespace std; 

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 

    int n;
    cin >> n;
    int arr[501][501] = {0}; 
    int result[501][501] = {0}; 
    for(int i = 0;i<n;i++) {
        for(int j = 0; j<=i;j++) {
            cin >> arr[i][j]; 
        }
    }

    result[0][0] = arr[0][0]; 
    result[1][0] = arr[1][0] + result[0][0];
    result[1][1] = arr[1][1] + result[0][0]; 
    for(int i = 2;i<n;i++) {
        result[i][0] = arr[i][0] + result[i-1][0]; 
        for(int j = 1;j<=i;j++) {
            int add = result[i-1][j-1] > result[i-1][j] ? result[i-1][j-1] : result[i-1][j]; 
            result[i][j] = arr[i][j] + add; 
        }
    }
    int max = 0; 
    for(int i = 0;i<n;i++) {
        max = max > result[n-1][i] ? max : result[n-1][i]; 
    }

    cout << max; 

    return 0;
}
