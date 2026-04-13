#include <iostream>
using namespace std; 

int board[41][2]; 

// 피보나치 함수 
int main(void) {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0); 

    #ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin); 
    freopen("./output.txt", "w", stdout); 
    #endif

    for(int i = 0;i<41; i++) {
        board[i][0] = 0; 
        board[i][1] = 0; 
    }

    board[0][0] = 1; 
    board[0][1] = 0;

    board[1][0] = 0; 
    board[1][1] = 1; 

    //board에 각각 0과 1이 몇번 나오는지를 작성한다. 
    //board[i][0] = i에서 0을 몇번 호출하는지에 대한 것이다.    
    for(int i = 2;i<41; i++) {
        board[i][0] = board[i-1][0] + board[i-2][0]; 
        board[i][1] = board[i-1][1] + board[i-2][1]; 
    }

    int num; 
    cin >> num; 
    for(int i = 0;i<num; i++) {
        int cnt; 
        cin >> cnt; 
        cout << board[cnt][0] << " " << board[cnt][1] <<'\n';
    }

    return 0; 
}
