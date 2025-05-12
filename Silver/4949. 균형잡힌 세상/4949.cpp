#include <iostream>
#include <string> 
#include <string.h>
#include <stack>
using namespace std; 

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(); 

    string input; 

    while(1){
        stack<char> memory; 
        getline(cin,input); 

        bool flag = true; 
        if(input == ".") break; 
        for(int i = 0; i<input.length(); i++){
            if(!flag) break; 
            if(input[i]=='('||input[i]=='[') memory.push(input[i]); 
            if(input[i]==']') {
                if(memory.empty()){
                    flag = false; 
                    continue; 
                }
                if(memory.top()=='['){
                    memory.pop(); 
                }else { 
                    flag = false;
                    continue;  
                }
            }else if(input[i]==')'){
                if(memory.empty()){ 
                    flag = false; continue; 
                }
                if(memory.top()=='('){
                    memory.pop(); 
                }else {
                    flag = false; continue; 
                }
            }
        }
        if(memory.empty()&&flag){
            cout << "yes" <<'\n';  
        }else {
            cout << "no"<<'\n';
        }
    }

    return 0;
}