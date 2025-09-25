#include <iostream>
using namespace std; 

int main(void) {
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    #ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin); 
    freopen("./output.txt", "w", stdout); 
    #endif

    int n;
    cin >> n;
    int input[10001]; 
    int map[10001]; 
    int prev = 0; 
    int a; 
    for(int i = 0;i<n;i++) {
        cin >> input[i];
    }
    
    map[0] = input[0]; 
    map[1] = input[1] + input[0]; 

    for(int i = 2; i<n;i++) {
        int max = map[i-1]; 
        if(max < map[i-2]+input[i]) max = map[i-2] + input[i];
        if(max < map[i-3]+input[i]+input[i-1]) max = map[i-3]+input[i]+input[i-1]; 
        map[i] = max; 
    }

    cout << map[n-1]; 

    return 0;
}
