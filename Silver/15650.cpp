#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std; 

int n ,m;
vector<int> num; 
int arr[10]= {0}; 

void input(){
    cin>> n>> m;
    int x; 
    for(int i = 0;i<n;i++){
        cin >> x;
        num.push_back(x);  
    }
    sort(num.begin() ,num.end()); 
}

void output(){
    for (int i = 0;i<m;i++){
        cout << arr[i] <<" "; 
    }
    cout << '\n'; 
}

void solve(int a,int b){
     
    if(b == m){
        output();
    }
    else { 
        for (int i = 0; i<n;i++){
            arr[b] = num[i];
            solve(i+1, b+1); 
        }
}
}

int main(void){
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    input(); 

    solve(0,0); 


    return 0;

}