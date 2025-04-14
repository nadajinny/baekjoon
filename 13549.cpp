#include <iostream>
#include <queue> 
#define MAX 0x3f3f3f3f
using namespace std; 

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    int n, m; 
    cin >> n >> m;

    bool visited[100001] = {0}; 
    int time[100001]; 
    
    queue<int> Q; 
    Q.push(n); 
    fill(time, time+100001, MAX); 
    time[n] = 0;
    while(!Q.empty()){
        int current = Q.front(); Q.pop(); 
        int move = current +1;

        if(move>=0&&move<=100000&&!visited[move]&&time[move]>=time[current]+1){
            Q.push(move); 
            time[move] = time[current] + 1; 
        }

        move = current -1; 
        if(move>=0&&move<=100000&&!visited[move]&&time[move]>=time[current]+1){
            Q.push(move); 
            time[move] = time[current] + 1; 
        }


        move = current*2; 
        if(move>=0&&move<=100000&&!visited[move]&&time[move]>=time[current]){
            Q.push(move); 
            visited[move] = true; 
            time[move] = time[current]; 
        }

    }

    cout << time[m]; 

    return 0;
}