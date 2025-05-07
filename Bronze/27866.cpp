#include <iostream>
#include <string> 
using namespace std; 

int main(void){
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    string a; 
    cin >> a; 
    int n; 
    cin >> n;
    cout << a[n-1]; 
    return 0;
}