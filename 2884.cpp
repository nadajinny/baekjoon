#include <iostream>
using namespace std; 


int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    int h, m;
    cin >> h >> m;
    
    int c_m = m - 45; 
    int c_h = h;
    if(c_m < 0 ) {
        c_h --; 
        c_m += 60 ; 
    }
    if(c_h<0) c_h += 24; 

    cout << c_h <<" "<< c_m; 

    return 0;
}