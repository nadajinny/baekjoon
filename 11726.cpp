#include <iostream>
using namespace std; 

int result[1001]= {0}; 

void solved(int n){
    result[1]= 1; 
    result[2]= 2; 
    for(int i = 3; i<=n; i++){
        result[i] = (result[i-1]+result[i-2])%10007; 
    }
    
    cout << result[n]; 
}

int main(void){
    ios::sync_with_stdio(); 
    cin.tie(); 

    int n;
    cin >> n;

    solved(n); 

    return 0;
}