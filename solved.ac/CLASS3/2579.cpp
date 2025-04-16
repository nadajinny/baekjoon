#include <iostream>

using namespace std; 

int level[301] = {0}; 
long long tot_level[301] = {0}; 



int main(void){
    ios::sync_with_stdio(); 
    cin.tie(); 
    
    int input; 
    cin >> input;

    for(int i = 0;i<input; i++){
        cin >> level[i+1]; 
    }

    tot_level[1]= level[1];
    tot_level[2] = level[1]+level[2];
    if(input <3){//계단 1, 2단일 때 예외 처리 
        cout << tot_level[input]; 
        return 0;
    }
    tot_level[3] = level[1]+level[3]>level[2]+level[3]?level[1]+level[3]:level[2]+level[3];
    
    for(int i = 4; i<=input; i++){
        tot_level[i] = level[i]+level[i-1]+tot_level[i-3]>level[i]+tot_level[i-2]?level[i]+level[i-1]+tot_level[i-3]:level[i]+tot_level[i-2];
    }
    cout << tot_level[input]; 
    return 0;
}