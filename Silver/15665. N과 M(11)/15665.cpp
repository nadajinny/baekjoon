#include <iostream>
#include <set> 
using namespace std; 

int n, m;
int arr[8]; 
int ans[8]; 
set<int> S; 

void func(int num) {
    if(num == m) {
        for (int i = 0;i<m;i++) cout << ans[i] <<' '; 
        cout << '\n'; 
        return ; 
    }
    for(int i = 0;i<n;i++) {
        ans[num] = arr[i]; 
        func(num+1); 
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
    int x;
    for(int i = 0;i<n;i++) {
        cin >> x; 
        S.insert(x); 
    }
    int j = 0; 
    for(auto i = S.begin(); i!= S.end(); i++){
        arr[j] = *i; 
        j++; 
    }

    n = j;  


    func(0); 


    return 0;
}
