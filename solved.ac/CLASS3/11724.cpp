#include <iostream>
#include <queue> 
using namespace std; 

int n,m;
bool input[1001][1001]={0}; 
bool visited[1001]={0}; 
queue<int> run; 
int result = 0;

void input2(){
    int a, b; 
    for(int i = 0;i<m;i++){
        cin >> a>>b; 
        input[a][b]= 1; 
        input[b][a]=1; 
    }
}

void count(){
    for(int i =1; i<=n;i++){
        if(visited[i]){
            continue; 
        }else {//연결되지 않은 새 노드부터 시작
            int from; 
            run.push(i); 
            while(!run.empty()){
                from = run.front(); 
                run.pop(); 
                for(int i = 1; i<=n; i++){
                    if(input[from][i] && !visited[i]){
                        visited[i]= true;
                        run.push(i); 
                    }
                }
            }
            result++; 
        }
    }
    cout << result; 
}

int main(void){
    ios::sync_with_stdio(); 
    cin.tie(); 

    cin >> n >>m;
    input2(); 

    count(); 


    return 0;
}