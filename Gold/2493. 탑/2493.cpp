#include <iostream>
#include <stack> 
using namespace std; 

int main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 

    #ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin); 
    freopen("./output.txt", "w", stdout); 
    #endif

    int top[500001]; 
    int result[500001]; 
    int n;
     
    cin >> n;
    int a;

    stack<pair<int,int>> check ; 
    for(int i = 0;i<n;i++) {
        cin >> top[i]; 
        if(i==0) result[i]= 0; 
        else {
            while(!check.empty()&&check.top().first < top[i]) {
                check.pop(); 
            }  
            if(!check.empty()) { result[i] = check.top().second+1; }
            else result[i] = 0; 
        }
        check.push({top[i], i}); 
    }

    for(int i = 0;i<n;i++) {
        cout << result[i] << " "; 
    }


    return 0;
}
