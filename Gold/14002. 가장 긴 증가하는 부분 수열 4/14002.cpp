#include <iostream>
#include <stack> 
using namespace std; 

int map[1000]; 
int len_size[1000]; 
int link_num[1000]; 
    
int main(void) {
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    #ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin); 
    freopen("./output.txt", "w", stdout); 
    #endif

    int n; 
    cin >> n;
    for(int i = 0;i<n;i++) cin >> map[i]; 

    int max = 0; 
    for(int i = 0;i<n;i++) {
        len_size[i] = 1;
        link_num[i] = -1; 

        for(int j = 0;j<i;j++) {
            if(map[j]<map[i] && len_size[i] < len_size[j]+1) {
                len_size[i] = len_size[j]+1; 
                link_num[i] = j; 
            }
        }
        if(len_size[max] < len_size[i]) { max = i; }
    }
    
    cout << len_size[max] << '\n';

    stack<int> result;
    for(int i = max; i!=-1; i = link_num[i]) {
        result.push(map[i]); 
    }

    while(!result.empty()){
        cout << result.top() << ' '; 
        result.pop(); 
    }
    return 0;
}
