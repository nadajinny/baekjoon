#include <iostream>
#include<vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    
    vector<int> a; 
    int n, x; 
    int sample;

    cin>>n>>x;

    for(int i=0;i<n;i++){
        cin>> sample;
        a.push_back(sample);
    }
    for(int i = 0;i<n;i++){
        if(a[i]<x) cout<<a[i]<<" ";
    }

}