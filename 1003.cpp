#include <iostream>
using namespace std; 


int cnt[41]={0,1,1};

void fibonacci(){
    for (int i = 3; i<41; i++){
        cnt[i]= cnt[i-1]+cnt[i-2]; 
    }
}

int main(void){
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    int n; 
    cin >> n;
    
    fibonacci();
    for(int i = 0;i<n;i++){
        int a ;
        cin >> a; 
        if (a == 0) cout << "1 0\n"; 
        else if(a==1) cout << "0 1\n"; 
        else {
            cout << cnt[a-1]<< ' '<< cnt[a]<<'\n'; 
        }
    }

    return 0;
}