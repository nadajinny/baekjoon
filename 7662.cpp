#include <iostream>
#include <string> 
#include <vector>
#include <algorithm> 
using namespace std; 

int main(void){
    ios::sync_with_stdio(); 
    cin.tie(); 

    int t; 
    cin >> t; 
    int k;
    string input; 
    int num; 
    vector<int> a; 
    for (int i =0; i<t; i++){
        cin >> k; 
        for(int j = 0;j<k;j++){
            cin >> input >> num; 
            if(input == "I"){//push
                a.push_back(num); 
                sort(a.begin(), a.end()); 
            }else if(!a.empty()&&input == "D"&&num == 1){//최댓값 삭제
                a.pop_back(); 
            }else if(!a.empty){//최솟값 삭제 
                a.erase(a.begin()); 
            }
        }
        if(a.empty()){
            cout <<"EMPTY"; 
            continue; 
        }
        for(auto j : a){
            cout << j <<" "; 
        }
        cout << '\n'; 
    }

    return 0;
}