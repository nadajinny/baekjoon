#include <iostream>
#include <stack>
using namespace std; 

int main(void)  {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 

    #ifndef ONLINE_JUDGE
    freopen("./input.txt", "r" , stdin); 
    freopen("./output.txt", "w", stdout); 
    #endif

    int n;
    cin >> n;

    int result[1000001]; 
    stack<pair<int,int>> checklist; 
    for(int i = 0;i<n;i++) {
        int m;
        cin >> m;

        while(!checklist.empty()) { //비교하기
            if(checklist.top().first < m) { //오큰수일 경우
                result[checklist.top().second] = m; 
                checklist.pop(); 
            } else break; 
        }

        checklist.push({m,i}); 
    }

    while(!checklist.empty()) {
        result[checklist.top().second] = -1; 
        checklist.pop(); 
    }

    for(int i = 0;i<n;i++) {
        cout << result[i] <<" "; 
    }

    return 0;
}
