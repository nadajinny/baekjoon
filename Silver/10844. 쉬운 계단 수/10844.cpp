#include <iostream>
using namespace std; 

int main(void) {
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    #ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin); 
    freopen("./output.txt", "w", stdout); 
    #endif
    int N; 
    
    cin >> N; 

    int cnt[10][2]; 
    cnt[0][0] = 0; 
    for(int i = 1;i<10;i++) cnt[i][0] = 1; 

    for(int i = 1; i<N+1; i++) {
        int nxt = i%2; 
        int cur = (i+1)%2; 
        cnt[0][nxt] = cnt[1][cur]; 
        cnt[0][nxt] %= 1000000000; 
        for(int j = 1; j<9; j++) {
            cnt[j][nxt] = cnt[j+1][cur] + cnt[j-1][cur]; 
            cnt[j][nxt] %= 1000000000; 
        }
        cnt[9][nxt] = cnt[8][cur]; 
        cnt[9][nxt] %= 1000000000; 
    }

    long long total = 0; 
    for(int i = 0;i<10; i++) {
        total += cnt[i][(N+1)%2]; 
        total %= 1000000000;
    }

    cout << total; 

    return 0;
}
