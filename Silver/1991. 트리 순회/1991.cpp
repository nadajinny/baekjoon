#include <iostream>
using namespace std; 

pair<char, char> tree[26]; 

void preorder(char i) {
    if(i == '.') return ; 

    cout << i ;
    preorder(tree[i-'A'].first); 
    preorder(tree[i-'A'].second); 
}

void inorder(char i) {
    if(i == '.') return ;

    inorder(tree[i-'A'].first); 
    cout << i ;
    inorder(tree[i-'A'].second); 
}

void postorder(char i) {
    if(i=='.') return ; 
    postorder(tree[i-'A'].first); 
    postorder(tree[i-'A'].second); 

    cout << i ; 
}

int main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 

    #ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin); 
    freopen("./output.txt", "w", stdout); 
    #endif

    //input
    int n; 
    cin >> n;
    char parent, left, right; 
    for(int i = 0; i<n; i++) {
        cin >> parent >> left >> right; 
        tree[parent-'A'].first = left; 
        tree[parent-'A'].second = right; 
    }

    //output
    preorder('A'); 
    cout << '\n';

    inorder('A'); 
    cout << '\n'; 

    postorder('A'); 

    return 0;
}
