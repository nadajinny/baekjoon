#include <iostream>
#include <queue> 
using namespace std; 

int time[100001] = {0}; 

int main(void) {
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    int n , m;
    cin >> n >> m;

    bool visited[100001] = {false}; 
    queue<int> q; 

    //time을 무조건 보다 크거나 같아야함. 
    //출력할 때에 -1해서 출력
    q.push(n); 
    while(!q.empty()){
        int current = q.front(); q.pop(); 
        if(current == m) break;
        //1증가, 1감소, 2배 
        int next = current+1; 
        if(next<=100000&&next>=0&&!visited[next]){
            visited[next] = true; 
            time[next] = time[current]+1;
            q.push(next); 
        }

        next = current-1; 
        if(next<=100000&&next>=0&&!visited[next]){
            visited[next] = true; 
            time[next] = time[current]+1;
            q.push(next); 
        }

        next = current*2; 
        if(next<=100000&&next>=0&&!visited[next]){
            visited[next] = true; 
            time[next] = time[current]+1;
            q.push(next); 
        }
    }

    cout << time[m]; 

    return 0;
    
}