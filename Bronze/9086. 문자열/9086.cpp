#include <iostream>
using namespace std; 
#include <string> 


int main(void){
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    int n; 
    cin >> n;
    for(int i = 0;i<n;i++){
        string a; 
        cin >> a; 
        cout << a[0]<<a[a.size()-1]<<'\n'; 
    }


    return 0;
}