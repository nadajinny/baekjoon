#include <iostream>
using namespace std; 

void checkout(string s) {
    bool flag = true;
    for(int i = 0;i<s.size()/2; i++) {
        if(s[i] != s[s.size()-1-i]) {
            flag = false;
            break; 
        }
    }

    if(flag) cout << "yes"; 
    else cout << "no"; 
    cout << '\n'; 

    return ; 
}

int main(void) {
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin); 
    freopen("../output.txt", "w", stdout); 
    #endif

    while(1) {
        string s; 
        cin >> s; 
        if(s == "0") break;
        checkout(s); 
    }

    return 0; 
}
