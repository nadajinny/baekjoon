#include <iostream>
#include <math.h>
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
    map[1] = 0;
    map[2] = 1; 
    map[3] = 1; 
    cin >> n;

    for(int i = 4;i<=n;i++) {
        map[i] = map[i-1] + 1; 
        if(i%2 == 0) map[i] = min(map[i], map[i/2]+1); 
        if(i%3 == 0) map[i] = min(map[i], map[i/3]+1); 
    }

    cout << map[n]<<'\n'; 

    while(1) {
        cout << n << " "; 
        if(n == 1) break; 
        if(n == 2 || n == 3) {cout << 1; break;}
        if(n%3==0&&map[n] == map[n/3] + 1 ) n = n/3; 
        else if(n%2==0&&map[n]==map[n/2]+1) n = n/2; 
        else n--;  
    }
    

    return 0;
}
