#include <iostream>
using namespace std; 

int dist[801][801]; 
vector<int> link[801]; 

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    int n, m;
    int result =0; 
    cin >> n>> m;
    
    int a, b, c; 
    for (int i = 0;i<m;i++){
        cin >> a >> b >> c; 
        dist[a][b] = c; 
        link[a].push_back(b); 
        link[b].push_back(a); 
    }

    cin >> a >> b; 

    //1~a 의 거리 + a~b의 거리 + b~result
    //1~b 의 거리 + b~a의 거리 + a~result 
    //둘 중 max 값 고르기 

    return 0;
}