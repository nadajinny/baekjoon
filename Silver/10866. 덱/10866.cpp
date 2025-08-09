#include <iostream>
#include <deque>
using namespace std; 

deque<int> dq; 

void push_back() {
    int n;
    cin >> n;
    dq.push_back(n);
}

void push_front() {
    int n;
    cin >> n;
    dq.push_front(n); 
}

void pop_back() {
    if(dq.empty()) {cout << "-1\n";  return ; }
    cout << dq.back() <<'\n'; 
    dq.pop_back(); 
}

void pop_front() {
    if(dq.empty()) {cout << "-1\n"; return ; }
    cout << dq.front() <<'\n'; 
    dq.pop_front(); 
}

void size() {
    cout << dq.size() << '\n'; 
}

void empty() {
    cout << dq.empty() <<'\n'; 
}

void front() {
    if(dq.empty()) cout << "-1\n"; 
    else cout << dq.front() <<'\n'; 
}

void back() {
    if(dq.empty()) cout << "-1\n"; 
    else cout << dq.back() <<'\n'; 
}

int main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 

    #ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin); 
    freopen("./output.txt", "w", stdout); 
    #endif

    int n;
    cin >> n;
    for(int i = 0;i<n;i++) {
        string order; 
        cin >> order; 
        
        if(order == "push_back") push_back(); 
        else if(order == "push_front") push_front(); 
        else if(order == "pop_front") pop_front(); 
        else if(order == "pop_back") pop_back(); 
        else if(order == "size")  size(); 
        else if(order == "empty") empty(); 
        else if(order == "front") front(); 
        else back(); 
    }

    return 0;
}
