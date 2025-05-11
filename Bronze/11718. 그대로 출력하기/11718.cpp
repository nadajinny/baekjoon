#include <iostream>
using namespace std; 

int main(void){
    string a; 
    while(1){
        getline(cin,a); 
        if(a == "") break;
        cout << a<<'\n'; 
    }
    return 0;
}