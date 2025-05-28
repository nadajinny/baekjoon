#include <iostream>
#include <string> 
#include <stack> 
using namespace std; 


int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(); 

    string input; 
    cin >> input; 

    stack<char> s; 
    stack<pair<int,int>> cal_s; //pair<number,calculation> -> cal = 1(add), cal=2(mul)
    int sum = 0;
    for(int i = 0;i<input.length(); i++) {
        char c = input[i]; 


        if(c=='('){
            s.push(c); 
            if(i!=input.length()-1){
                if(input[i+1]==')') cal_s.push({2,1}); 
                else cal_s.push({2,2}); 
            }else {sum=0; break;}
        }else if( c=='[' ){
            s.push(c); 
            if(i!=input.length()-1){ 
                if(input[i+1]==']') cal_s.push({3,1}); 
                else cal_s.push({3,2}); 
            }else { sum=0; break;}
        }
        
        
        else if( c==')' ){
            if(s.empty()){sum = 0 ; break;}
            if(s.top()=='('){
                if(cal_s.top().second==1){
                    sum+=cal_s.top().first; 
                    cal_s.pop(); 
                    cout << sum << ' '; 
                }else {
                    sum*=cal_s.top().first;
                    cal_s.pop();  
                    cout << sum << ' '; 
                }
                s.pop(); 
            }else {    sum = 0; cout << 5; break;    }
        }else if( c == ']'){
            if(s.empty()){sum = 0 ; cout << 6; break;}
            if(s.top()=='['){
                if(cal_s.top().second==1){
                    sum+=cal_s.top().first; 
                    cal_s.pop();
                    cout << sum << ' ';  
                }else {
                    cal_s.push(sum*cal_s.top().first);
                    sum*=cal_s.top().first;
                    cal_s.pop();  
                    cout << sum <<' ';
                }
                s.pop(); 
            }else { sum =0; break ;}
        }
    }

    cout <<'\n'<< sum;

    return 0;
}