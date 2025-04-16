#include <iostream>
#include <string>
#include <array> 
using namespace std; 

bool exist[21]; 

int main(void){
    ios::sync_with_stdio(0); 
    cin.tie(); 
    cout.tie(); 

    int n;
    cin >> n;
    string input; 
    int m;
    for(int i = 0;i<n;i++){
        cin >> input; 

        if(input == "add"){
            cin >> m;
            exist[m]=true; 
        }else if(input == "remove"){
            cin >> m;
            exist[m]=false; 
        }else if(input == "check"){
            cin >> m;
            if(exist[m]){
                cout << 1 <<'\n';
            }else {
                cout << 0 <<'\n'; 
            } 
        }else if(input == "toggle"){
            cin >> m;
            if(exist[m]){
                exist[m]=false;
            }else {
                exist[m]=true; 
            }
        }else if(input == "all"){
            fill_n(exist, 21, true); 
        }else {
            fill_n(exist, 21, false); 
        
        }
    }

    return 0;
}