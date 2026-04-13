#include <iostream>
using namespace std; 

int main(void){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
       
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin); 
    freopen("../output.txt", "w", stdout); 
    #endif

    int a; 
    int b; 
    cin >> a >> b;
    cout.precision(9); 
    cout << (double)a/b; 
    return 0; 
}
