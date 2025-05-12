#include <iostream>
#include <string> 
#include <stack> 
using namespace std; 

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(); 

    int n;
    cin >> n;

    for(int j =0;j<n;j++){
        string input; 
        stack<char> s; 
        cin >> input; 
        for(int i = 0;i<input.length(); i++){
            char a = input[i]; 
            if(a == '('||a=='[') { s.push(a); continue; }
            if(s.empty()) {s.push(a); break; }
            if(a == ')'){
                if(s.top()!='(') break; 
                s.pop(); 
            }
            if(a ==']'){
                if(s.top()!='[') break; 
                s.pop(); 
            }

        }
        if(s.empty()) {
            cout <<"YES"<<'\n';
        }else {
            cout << "NO" << '\n'; 
        }
    }

    return 0;
}