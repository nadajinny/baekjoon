#include <iostream>
#include <queue> 
using namespace std; 

int main(void){
    ios::sync_with_stdio(0); 
    cin.tie(); 

    int n;
    cin >> n;
    int order; 
    priority_queue<int, vector<int>, greater<int>> input; 
    for(int i = 0;i<n;i++){
        cin >> order; 
        if(!order){
            if(input.empty()) printf("0\n");
            else{
                printf("%d\n",input.top()); 
                input.pop(); 
            }
        }else {
            input.push(order); 
        }
    }

    return 0;
}