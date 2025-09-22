    #include <iostream>
    using namespace std; 

    int main(void) {
        ios::sync_with_stdio(0); 
        cin.tie(0); 

        #ifndef ONLINE_JUDGE
        freopen("./input.txt", "r", stdin); 
        freopen("./output.txt", "w", stdout); 
        #endif

        long long map[91]; 
        int n;
        cin >> n;
        map[0] = 0; 
        map[1] = 1; 
        map[2] = 1; 

        for(int i = 3; i<=n; i++) {
            map[i] = map[i-1] + map[i-2]; 
        }

        cout << map[n]; 

        return 0;
    }
