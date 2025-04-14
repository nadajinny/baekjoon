#include <iostream>
#include <string> 
using namespace std; 

int main(void){
    string a;
    int n;
    cin >> n;
    cin >> a; 
    int tot = 0; 
    for(int i =0;i<n;i++){
        int sum = a[i]-'0'; 
        tot += sum; 
    }
    cout << tot; 

}