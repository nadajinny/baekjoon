#include <iostream>
using namespace std; 

int main(void) {
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    #ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin); 
    freopen("./output.txt", "w", stdout); 
    #endif

    int n;
    cin >> n; 

    int day[16]; 
    int money[16]; 
    int result[16] = {0}; 
    for(int i = 0;i<n;i++) {
        int a; 
        cin >> day[i] >> money[i]; 
    }


    for(int i = 0;i<n;i++) {
        result[i+1] = result[i+1] > result[i] ? result[i+1] : result[i]; 

        int end_date = i+day[i]; 
        if(end_date <= n) {
            result[end_date] = result[end_date] > result[i] + money[i]? result[end_date]: result[i]+money[i]; 
        }
    }
    cout << result[n]; 
    return 0;
}
