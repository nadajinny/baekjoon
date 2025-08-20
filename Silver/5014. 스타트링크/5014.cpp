#include <iostream>
#include <queue> 
using namespace std; 

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    #ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin); 
    freopen("./output.txt", "w", stdout); 
    #endif

    int F, S, G, U, D; 
    cin >> F >> S >> G >> U >> D ; 

    queue<int> pos; 
    int visited[1000001] = {0}; 
    pos.push(S); 
    int cnt = 0;
    int flag = 0;  
    visited[S] = 1; 

    if(S==G) {cout << cnt; return 0;}
    
    while(!pos.empty()) {  
        cnt++; 
        int sz = pos.size(); 
        for(int i = 0; i<sz; i++) {
            int cur = pos.front(); 
            pos.pop(); 
            

            int nxt = cur+ U; 

            if(nxt > F || nxt < 1) {}
            else if(visited[nxt]) {}
            else {
                visited[nxt] = 1; 
                pos.push(nxt);
                if(nxt == G) flag = 1; 
            }

            nxt = cur-D; 

            if(nxt > F || nxt < 1) {}
            else if(visited[nxt]) {}
            else {
                visited[nxt] = 1; 
                pos.push(nxt);
                if(nxt == G) flag = 1; 
            }
        }

        if(flag) break; 
    }

    if(flag) cout << cnt; 
    else cout << "use the stairs"; 

    return 0;
}
