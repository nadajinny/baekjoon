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

    long long map[100001]; 
    int a; 
    cin >> map[0]; 

    for(int i = 1;i<n;i++) {
        cin >> a; 
        map[i] = map[i-1] + a; 
    }

    long long max = map[0]; 
    long long sub = 0; 
    if(sub > map[0]) sub = map[0]; 
    for(int i = 1;i<n;i++) {
        if(max < map[i]-sub) max = map[i]-sub; 
        if(sub > map[i]) sub = map[i]; 
    }

    cout << max; 

    return 0;
}
