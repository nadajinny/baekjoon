#include <iostream>
using namespace std; 

int n,m; 
int arr[7]; 
bool isused[7]; 

void func(int x) {
    if(x == m) {
        for(int i = 0;i<m;i++) cout << arr[i] << ' '; 
        cout << '\n'; 
        return ; 
    } 

    for(int i = 1;i<=n;i++) {
            arr[x] = i; 
            isused[i] = 1; 
            func(x+1); 
            isused[i] = 0; 
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

    func(0); 

    return 0;
}
