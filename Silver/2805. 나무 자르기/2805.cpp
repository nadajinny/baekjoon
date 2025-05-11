#include <iostream>
#include <algorithm> 
using namespace std; 

int tree; 
long long goal; 
long long tree_size[1000001]; 

void binary_search(){
    long long low = 0; 
    long long high = tree_size[tree-1]; 
    long long max = 0; 
    while(low<=high){
        long long tot = 0; 
        long long mid = (low+high)/2; 

        for(int i = 0; i<tree;i++){
            if(tree_size[i]>mid) tot += tree_size[i]-mid; 
        }
        if(tot>=goal) {
            max = mid; 
            low = mid + 1; 
        }
        else {
            high = mid-1; 
        }
    }

    cout << max; 

}

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(); 

    cin >> tree>>goal ; 

    for(int i = 0;i<tree; i++){
        cin >> tree_size[i]; 
    }

    sort(tree_size, tree_size+tree); 

    binary_search(); 

    return 0;
}