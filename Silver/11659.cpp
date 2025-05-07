#include <iostream>
using namespace std; 

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n, m;
    cin >> n>> m;
    int arr[100001]; 
    arr[0]=0; 
    int input; 
    for(int i = 1; i <= n; i++){
        cin >> input;
        arr[i] = arr[i-1] + input;
    }
    for(int i = 0;i<m;i++){
        int a, b; 
        cin >> a >> b;
        cout << arr[b] - arr[a-1] << "\n";
    }
}