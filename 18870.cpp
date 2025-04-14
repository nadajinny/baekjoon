#include <iostream>
#include <vector> 
#include <queue> 
#include <set> 
#include <map> 
#include <algorithm>
using namespace std; 


int main(void){
    ios::sync_with_stdio(); 
    cin.tie(); 

    int n;
    cin >> n;
    int x; 
    
    vector<int> b; 
    queue<int> c; 
    for(int i = 0;i<n;i++){
        cin >> x; 
        c.push(x); 
        b.push_back(x); 
    }

    sort(b.begin(), b.end()); 
    b.resize(unique(b.begin(), b.end())-b.begin()); 
    
    map<int,int> find_map;
    for(int i = 0;i<b.size(); i++){
        find_map[b[i]] = i;
    }

    while(!c.empty()){
        cout << find_map[c.front()] << " ";
        c.pop(); 
    }
    return 0;
}