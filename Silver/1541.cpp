#include <iostream>
#include <string> 
using namespace std; 

string input; 

int search(){
    int sub = 0; 
    int result = 0;
    for(int i = 0;i<input.size(); i++){
        if(input[i]=='-'){
            i++;
            while(input[i]!='-'&&i<input.size()){
                if(isdigit(input[i])){
                    sub = sub*10 + input[i]-'0'; 
                    cout << sub<<' '; 
                }
                else {
                    result -= sub; 
                    sub = 0; 
                }
                i++; 
            }
        }
        if(input[i] == '+'){
            int add = 0; 
            while(isdigit(input[i]&&i<input.size())){
                add = add*10 + input[i]-'0'; 
                i++; 
            }
            result += add; 
        }
        else {
            int add =0; 
            while(isdigit(input[i]&&i<input.size())){
                add = add*10 +input[i]-'0'; 
                i++; 
            }
            result += add; 
        }
    }

    return result; 
}


int main(void){
    ios::sync_with_stdio(0); 
    cin.tie(); 

    cin >> input; 
    cout << search(); 
    

    return 0;
}