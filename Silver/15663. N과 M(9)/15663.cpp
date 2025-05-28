#include <iostream>
#include <algorithm>
using namespace std;

int result[9]; 
bool checked[9]; 
int arr[9]; 
int n, m;
void input() {
    for(int i = 0; i<n;i++){
        cin >> arr[i]; 
    }
    sort(arr, arr+n); 
}

void backtracking( int cnt) {
    if(cnt == m) {
        for(int i = 0;i<m;i++) {
            cout << result[i] <<' '; 
        }
        cout << '\n'; 
        return ; 
    }
    int prev = -1; 
    for(int i = 0; i<n;i++) {
        if(!checked[i]&&prev!=arr[i]) {
            checked[i] = true; 
            result[cnt] = arr[i]; 
            prev = arr[i]; 
            backtracking(cnt+1); 
            checked[i] = false; 
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie();
    
    cin >> n >> m;

    input(); 
    backtracking(0); 


    return 0;
}