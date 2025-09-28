#include <iostream>
#define DIV 1000000000
using namespace std; 

int main(void) {
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    #ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin); 
    freopen("./output.txt", "w", stdout); 
    #endif

    int n;
    int map[1000001]; 

    map[0] = 0;
    map[1] = 1; 

    int mul = 1; 

    cin >> n;

    if(n<0) {mul = -1;   n *= -1; }
    else if(n == 0) {
        cout << 0 <<'\n' << 0; 
        return 0;
    }

    for(int i = 2; i<=n;i++) {
        map[i] = (map[i-2] + map[i-1]*mul)%DIV; 
    }

    if(map[n]<0) cout << -1 <<'\n' << -map[n];
    else cout << 1 <<'\n'<<map[n]; 
    

    return 0;
}
