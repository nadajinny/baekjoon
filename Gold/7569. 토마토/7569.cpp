#include <iostream>
#include <queue> 
using namespace std; 

int box[101][101][101]; 
int m=0, n=0, h=0; 
int tot_tomato = 0; 
int check_tomato = 0; 
int days = 0; 

int dm[6] = {-1,+1,0,0,0,0}; 
int dn[6] = {0,0,-1,+1, 0,0}; 
int dh[6] = {0,0,0,0,-1,+1}; 

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    #ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin); 
    freopen("./output.txt", "w", stdout); 
    #endif

    cin >> m >> n >> h;

    queue<pair<int,pair<int,int>>> cur_queue; 
    queue<pair<int,pair<int,int>>> nxt_queue; 

    for(int h_i = 0;h_i<h;h_i++) {
        for(int n_i = 0; n_i < n; n_i++) {
            for (int m_i = 0; m_i < m; m_i++) { 
                cin >> box[m_i][n_i][h_i]; 
                if(box[m_i][n_i][h_i]!=-1) tot_tomato++; 
                if(box[m_i][n_i][h_i]== 1) {nxt_queue.push({m_i,{n_i,h_i}});  check_tomato++; }
            }
        }
    }

    if (tot_tomato == check_tomato) { cout << 0; return 0; }

    while(!nxt_queue.empty()) {
        cur_queue = nxt_queue; 
        queue<pair<int,pair<int,int>>> empty;
        swap(nxt_queue, empty);  
        while(!cur_queue.empty()) {
                pair<int,pair<int,int>> cur_mnh = cur_queue.front(); 
                cur_queue.pop(); 
                int cur_m = cur_mnh.first; 
                int cur_n = cur_mnh.second.first; 
                int cur_h = cur_mnh.second.second; 

                for(int dir = 0;dir<6; dir++) {
                    int nxt_m = cur_m + dm[dir]; 
                    int nxt_n = cur_n + dn[dir]; 
                    int nxt_h = cur_h + dh[dir]; 

                    if(nxt_m<0||nxt_n<0||nxt_h<0||nxt_m>=m||nxt_n>=n||nxt_h>=h) continue;
                    if(box[nxt_m][nxt_n][nxt_h]==-1||box[nxt_m][nxt_n][nxt_h]==1) continue;

                    box[nxt_m][nxt_n][nxt_h] = 1; 
                    nxt_queue.push({nxt_m,{nxt_n,nxt_h}}); 

                    check_tomato++; 
                }

                if(check_tomato==tot_tomato) break;
        }
        days++; 
        if(check_tomato == tot_tomato) break;
        
    }

    if(check_tomato==tot_tomato) cout << days;
    else cout << -1; 

    return 0;
}
