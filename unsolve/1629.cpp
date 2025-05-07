#include <iostream>
using namespace std; 


int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    long long int a, b, c; 
    long long int result =1; 
    cin >> a >> b >> c; 
    for(int i =0;i<b; i++){
        result *= a%c;
    }
    cout << result; 

    return 0;
}