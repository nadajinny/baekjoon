#include <iostream>
using namespace std; 

bool paper[130][130] = {0}; 

void solved(int n){
    int result = 0; 
    int div = n;

    while(div >= 1) {
        for(int start_i = 0; start_i < n; start_i += div){
            for(int start_j = 0; start_j < n; start_j += div){
                bool tag = true;

                for(int i = start_i; i < start_i + div; i++){
                    for(int j = start_j; j < start_j + div; j++){
                        if(!paper[i][j]) {
                            tag = false;
                            break;
                        }
                    }
                    if(!tag) break;
                }

                if(tag){
                    result++;
                    for(int i = start_i; i < start_i + div; i++){
                        for(int j = start_j; j < start_j + div; j++){
                            paper[i][j] = 0;
                        }
                    }
                }
            }
        }

        div /= 2; 
    }

    cout << result;
}


int main(void){
    ios::sync_with_stdio(); 
    cin.tie(); 
    
    int n;
    cin >> n;
    int input; 
    bool full = 1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> input; 
            paper[i][j]= input;
            if(input) full= 0; 
        }
    }

    if(full) {cout << 1; return 0;}

    solved(n); 


    return 0;
}