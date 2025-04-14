#include <iostream>
#include <vector> 
#include <string> 
#include <algorithm>
using namespace std; 

vector<pair<string, string>> a; 

int binary_search(string target){
    int low = 0 , high = a.size()-1; 

    while(low<=high){
        int mid = (low+high)/2; 
        if(target == a[mid].first) return mid; 
        if(target < a[mid].first) high = mid-1; 
        else if(target >a[mid].first) low = mid+1; 
    }
    return 0; 
}

int main(void){
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    int n, m;
    cin >> n >> m;

    string input, input2; 
    for(int i =0;i<n;i++){
        cin >> input>>input2; 
        a.push_back({input,input2}); 
    }   
    sort(a.begin(), a.end()); 
    for(int i = 0;i<m;i++)  {
        cin >> input; 
        cout << a[binary_search(input)].second<<'\n'; 
    }

    return 0;
}