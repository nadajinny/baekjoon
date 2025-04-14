#include <iostream>
#include <queue> 
using namespace std; 

int main(void){
    ios::sync_with_stdio(); 
    cin.tie(); 

    int n;
    cin >> n;
    int input; 
    priority_queue<int> test;

    for(int i = 0;i<n;i++){
        scanf("%d",&input); 

        if(input!=0){
            test.push(input); 
        }else if(test.empty()){
            printf("0\n"); 
        }else {
            printf("%d\n",test.top() ); 
            test.pop(); 
        }
    }

    return 0;
}