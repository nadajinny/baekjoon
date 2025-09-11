#include <iostream>
#include <algorithm>
using namespace std; 

int n, m;
int arr[8]; 
int isused[8]; 
int arr2[8]; 

void func(int x, int y) {
    if(x == m) {
        for(int i = 0;i<m;i++) cout << arr2[i] <<' '; 
        cout << '\n'; 
        return ; 
    }
    for(int i = y;i<n;i++) {
        if(!isused[i]) {
            arr2[x] = arr[i]; 
            isused[i] = 1; 
            func(x+1, i+1); 
            isused[i] = 0; 
        }
    }
}


int main(void) {
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    #ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin); 
    freopen("./output.txt", "w", stdout); 
    #endif

    cin >> n >> m;

    for(int i = 0;i<n;i++) {
        cin >> arr[i]; 
    }
    
    sort(arr,arr+n); 

    func(0, 0); 



    return 0;
}
