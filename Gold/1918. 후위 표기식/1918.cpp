#include <iostream>
#include <stack>
#include <queue> 

using namespace std; 


int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    #ifndef ONLINE_JUDGE
    freopen("./input.txt","r", stdin); 
    freopen("./output.txt","w",stdout); 
    #endif

    string s; 
    stack<char> oper; 
    cin >> s; 

    for(int i=0;i<s.length(); i++) {
        if(s[i]>='A'&&s[i]<='Z') cout << s[i]; 
        else if(s[i]=='(') oper.push(s[i]); 
        else if(s[i]==')') {
            while(!oper.empty()) {
                if(oper.top()=='(') {oper.pop(); break; }
                cout << oper.top() ; 
                oper.pop(); 
            }
        }
        else if(s[i]=='/' || s[i]=='*') {
            while(!oper.empty()) {
                if(oper.top()!='/'&&oper.top()!='*') break; 
                cout << oper.top(); 
                oper.pop(); 
            }
            oper.push(s[i]); 
        }
        else if (s[i]=='+'||s[i]=='-') {
            while(!oper.empty()) {
                if(oper.top()=='(') break; 
                cout << oper.top(); 
                oper.pop(); 
            }
            oper.push(s[i]); 
        }
    }

    while(!oper.empty()) {
        cout << oper.top() ; 
        oper.pop(); 
    }

    return 0;
}
