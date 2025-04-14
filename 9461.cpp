#include <iostream>
using namespace std; 


int main(void){
    ios::sync_with_stdio(); 
    cin.tie(); 
    cout.tie(); 

    long long p[101] = {0,1,1,1,0}; 
    for(int i = 3; i<101; i++){
        p[i] = p[i-2]+p[i-3];
    }

    int n,m; 
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> m;
        cout << p[m]<<'\n'; 
    }

    return 0;
}