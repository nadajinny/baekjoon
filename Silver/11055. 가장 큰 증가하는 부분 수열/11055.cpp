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

    int arr[1001]; 
    long long map[1001]; 
    long long max = 0; 

    for(int i = 0;i<n;i++) {
        int add = 0; 
        cin >> arr[i]; 
        map[i] = arr[i]; 
        if(i == 0) max = map[i]; 
        for(int j = i-1;j>=0; j--) {
            if(arr[i]>arr[j]) {
                if(add < map[j]) add = map[j]; 
            }
        }
        map[i] = map[i] + add;
        if(max < map[i]) max = map[i]; 
    }

    cout << max; 

    return 0;
}
