#include <iostream>
#include <string> 
#include <stack> 

using namespace std; 

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(); 

    string a; 
    stack<char> s; 
    int tot = 0; 
    cin>> a; 
    int pipe = 0; 

    for(int i = 0;i<a.length(); i++){
        char c = a[i]; 
        if(c==')'){
            pipe--; 
            if(a[i-1]=='(')  tot+=pipe; 
            else tot++; 
        }else {
            pipe++; 
        }
    }
    cout << tot ; 


    return 0;
}