#include <iostream>
using namespace std; 


int main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 

    #ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin); 
    freopen("./output.txt", "w", stdout);
    #endif

    int n;
    cin >> n; 
    int map[2][100000]; 
    int result[2][100000]; 
    for(int k = 0;k<n;k++) {
        int line; 
        cin >> line; 
        for(int i = 0;i<2; i++ ){
            for(int j =0; j<line; j++) cin >> map[i][j]; 
        }
        result[0][0] = map[0][0]; 
        result[1][0] = map[1][0]; 
        result[0][1] = map[1][0] + map[0][1]; 
        result[1][1] = map[0][0] + map[1][1]; 

        for(int i = 2; i<line; i++) {
            int add = result[1][i-2] > result[1][i-1] ? result[1][i-2] : result[1][i-1]; 
            result[0][i] = add + map[0][i]; 

            add = result[0][i-2] > result[0][i-1] ? result[0][i-2] : result[0][i-1]; 
            result[1][i] = add + map[1][i]; 
        }
        int output = result[0][line-1] > result[1][line-1] ? result[0][line-1] : result[1][line-1]; 
        cout << output << '\n';
    }

    return 0;
}
