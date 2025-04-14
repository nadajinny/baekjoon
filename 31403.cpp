#include <iostream>
#include <string> 
using namespace std; 


int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    string a, b, c; 

    cin >> a >> b >> c; 
    cout << atoi(a.c_str())+atoi(b.c_str())-atoi(c.c_str()) << '\n'; 
    a.append(b); 
    cout << atoi(a.c_str()) - atoi(c.c_str()); 

    return 0;

}