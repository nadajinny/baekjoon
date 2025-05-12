#include <iostream>
#include <stack> 
#include <string>
using namespace std; 


int main(void)  {
    ios::sync_with_stdio(false); 
    cin.tie(); 

    int n;
    int cnt = 0; 
    cin >> n;
    for(int i = 0;i<n;i++){
        string input ; 
        cin >> input; 
        stack<char> check; 
        for(int j =0;j<input.length(); j++){
            char a = input[j];
            if(a == 'A'){
                if (!check.empty()){
                    if(check.top()=='A'){
                        check.pop(); 
                    }
                    else {
                        check.push(a); 
                    }
                }
                else {
                    check.push(a); 
                }
            }else if(a == 'B'){
                if (!check.empty()){
                    if(check.top()=='B'){
                        check.pop(); 
                    }else {
                        check.push(a);  
                    }
                }else {
                    check.push(a); 
                }
            }
        }
        if(check.empty()){
            cnt++; 
        }
    }
    cout << cnt; 


    return 0;
}