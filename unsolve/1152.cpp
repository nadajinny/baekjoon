#include <iostream>
#include <string> 
using namespace std; 


int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    string a; 
    getline(cin , a); 
    int tot = 1;
    int cnt = 0;  
    for(int i = 0;i<a.size(); i++){
        if(a[i]==' ') cnt++; 
        else {
            if (cnt > 0)tot ++; 
            cnt = 0; 
        }
    }
    cout << tot; 

    return 0;
}