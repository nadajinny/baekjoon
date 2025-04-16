#include <iostream>
#include <string> 
#include <vector> 
using namespace std;


int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    string input; 
    vector<char> output; 
    cin >> input; 

    for(int i = 0;i<input.size(); i++){
        if(input[i]>='A'&&input[i]<='Z') output.push_back(tolower(input[i])); 
        else if(input[i]>='a'&&input[i]<='z') output.push_back(toupper(input[i])); 
    }
    for(int i = 0;i<output.size(); i++){
        cout << output[i]; 
    }
    
    return 0;
}