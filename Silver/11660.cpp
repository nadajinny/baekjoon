#include <iostream>
using namespace std; 

int arr[1025][1025]; 
int added[1025][1025]; 

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    int n, m;
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        int tot = 0; 
        for(int j = 0;j<n;j++){
            cin >> arr[i][j];
            tot +=  arr[i][j]; 
            added[i][j] = tot;  
        }
    }

    int fromX, fromY, endX, endY ; 
    for(int i =0;i<m;i++){
        cin >> fromX >> fromY >> endX >> endY; 
        int tot = 0; 
        for (int j = fromX-1; j<endX; j++) {
            if(fromY==1) tot+= added[j][endY-1];
            else {tot+= added[j][endY-1]-added[j][fromY-2];}} 
        cout << tot<< '\n'; 
    }

    return 0;
}



// #include <iostream>
// using namespace std;

// int arr[1025][1025];
// int prefix[1025][1025];

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n, m;
//     cin >> n >> m;

//     // 입력 + 누적합 계산
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= n; j++) {
//             cin >> arr[i][j];
//             prefix[i][j] = arr[i][j] 
//                          + prefix[i-1][j] 
//                          + prefix[i][j-1] 
//                          - prefix[i-1][j-1];
//         }
//     }

//     // 쿼리 처리
//     for (int i = 0; i < m; i++) {
//         int x1, y1, x2, y2;
//         cin >> x1 >> y1 >> x2 >> y2;

//         int result = prefix[x2][y2]
//                    - prefix[x1 - 1][y2]
//                    - prefix[x2][y1 - 1]
//                    + prefix[x1 - 1][y1 - 1];

//         cout << result << '\n';
//     }

//     return 0;
// }



