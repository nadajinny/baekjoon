#include <iostream>
using namespace std; 

int cnt = -1; 
int N, r, c; 
int dy[4] = {0,0,1,1}; 
int dx[4] = {0,1,0,1}; 
bool flag = false; 

void z(int y, int x) {
    for(int i = 0;i<4; i++) {
        int y2 = y + dy[i]; 
        int x2 = x + dx[i]; 
        cnt ++ ; 
        if(y2 == r && x2 == c) {flag = true; break; }
    }
    if(flag) return ; 
}


void divide(int size, int start_x, int start_y) {
    if (flag) return;

    if (size == 2) {
        z(start_y, start_x);  
        return;             
    }

    if (r < start_y || r >= start_y + size || c < start_x || c >= start_x + size) {
        cnt += size * size;
    } else {
        divide(size / 2, start_x, start_y);
        divide(size / 2, start_x + size / 2, start_y);
        divide(size / 2, start_x, start_y + size / 2);
        divide(size / 2, start_x + size / 2, start_y + size / 2); 
    }
}

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    #ifndef ONLINE_JUDGE
    freopen("./input.txt","r",stdin); 
    freopen("./output.txt", "w", stdout);
    #endif

    cin >> N >> r >> c; 
    int size = 1; 
    for(int i = 0;i<N; i++) {
        size *= 2; 
    }

    
    divide(size, 0,0); 

    cout << cnt ; 

    return 0;
}
