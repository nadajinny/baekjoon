#include <iostream>
#include <vector> 
using namespace std; 


vector<int> v;

void postOrder(int front, int end){
    if(front >= end) return; 
    if(front == end-1) { cout << v[front] <<'\n'; return; }
    int check = front + 1; 
    while(check < end) {
        if(v[front]<v[check]) break;
        check ++; 
    }

    postOrder(front+1, check); 
    postOrder(check, end); 
    cout << v[front] << '\n'; 


}


int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    int t;
    int cnt = 0; 
    while(cin >> t) {
        v.push_back(t);
        cnt++; 
    }

    postOrder(0,cnt); 

    return 0;
}