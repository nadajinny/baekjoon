#include <iostream>
#include <queue> 
using namespace std; 
int n;

void test(){
    queue<pair<int,int>> tester; 
    tester.push({n,0}); 
    int cnt ; 
    while(1){
        n = tester.front().first; 
        cnt = tester.front().second; 
        if(n == 1) break; 
        tester.pop(); 
        if(n%3==0){
            tester.push({n/3, cnt+1}); 
        }
        if(n %2==0){
            tester.push({n/2, cnt+1});
        }
        tester.push({n-1, cnt+1}); 
    }
    cout << cnt; 
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n;
    test();

    return 0;
}