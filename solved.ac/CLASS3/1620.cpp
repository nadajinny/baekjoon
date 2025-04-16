#include <iostream>
#include <map> 
#include <string> 
using namespace std;

map<string, int> pokemon; 
string pokemonname[100001]; 
void search(int cnt){
	string input; 
	for(int i = 0;i<cnt; i++){
		cin >> input; 
		if(isdigit(input[0])){
			cout << pokemonname[stoi(input)-1] << '\n'; 
		}else {
			cout << pokemon.find(input)->second <<'\n'; 
		}
	}
}

int main(void){
	ios::sync_with_stdio(0); 
	cin.tie(0); 

	int n, m;
	cin >> n>>m;
	string input; 
	for(int i = 0;i<n; i++){
		cin >> input; 
		pokemon.insert({input, i+1}); 
		pokemonname[i]= input; 
	}

	search(m); 

	return 0;
}