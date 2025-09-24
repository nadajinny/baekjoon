#include <iostream>
using namespace std; 

int T[1500001]; 
int P[1500001]; 
long long total[1500001]; 

int main(void) {
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    #ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin); 
    freopen("./output.txt", "w", stdout); 
    #endif

    int n;
    cin >> n;
    for(int i = 0;i<n;i++) cin >> T[i] >> P[i]; 

    for(int i = 0;i<n;i++) {
        total[i+1] = total[i] > total[i+1] ? total[i] : total[i+1]; 
        
        long long end_date = i + T[i]; 
        if(end_date <= n) total[end_date] = total[end_date] > total[i] + P[i] ? total[end_date] : total[i] + P[i]; 
    }

    cout << total[n]; 

    return 0;
}
