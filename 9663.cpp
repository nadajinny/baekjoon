#include <iostream>
#include <vector> 
using namespace std; 

int n;
int result= 0; 
void check(vector<int>& testcase, int y){
    if(y == n){
        result++; 
        return; 
    }

    for(int x = 0;x<n;x++){
        bool safe = true; 
        for(int i = 0;i<y; i++){
            if(x == testcase[i]||abs(testcase[i]-x)==abs(i-y)){
                safe = false; 
                break;
            }
        }
        if(safe == true){
            testcase.push_back(x); 
            check(testcase,y+1); 
            testcase.pop_back(); 
        }
    }
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 

    cin >> n;
    vector<int> testcase; 

    check(testcase, 0); 
    
    cout << result ; 

    return 0;

}