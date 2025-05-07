#include <iostream>
using namespace std; 

int cnt[12]= {1,2,4}; 

int main(void){
    ios::sync_with_stdio(); 
    cin.tie(); 
    cout.tie(); 

    int n,m;
    cin >> n;

    for(int i = 3; i<=12;i++){
        cnt[i] = cnt[i-1]+cnt[i-2]+cnt[i-3]; 
    }

    for(int i = 0;i<n;i++){
        cin >> m;
        cout << cnt[m-1]<<'\n'; 
    }

    return 0;
}