#include <iostream>
#include <algorithm>

using namespace std; 

int n,m ;
bool isused[8]; 
int arr[8]; 
int ans[8]; 

void func(int num, int start){
    if(num == m) {
        for(int i = 0;i<m; i++)  {
            cout << ans[i]<<' ';
        }
        cout << '\n'; 
        return ; 
    }
    int prev = -1; 

    for(int i = start; i<n;i++) {
        if(prev==arr[i]) continue; 
        ans[num] = arr[i]; 
        func(num+1, i+1); 
        prev = arr[i]; 
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
    sort(arr, arr+n); 


    func(0, 0); 
    
    return 0;
}
