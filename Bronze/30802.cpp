#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int s, m, l, xl, xxl, xxxl;
	cin >> s >> m >> l >> xl >> xxl >> xxxl;
	int t, p;
	cin >> t >> p;
	int cnt1; 
	int cnt2; 
	if (s % t != 0) cnt1++; 
	if (m % t != 0) cnt1++;
	if (l % t != 0) cnt1++;
	if (xl % t != 0) cnt1++;
	if (xxl % t != 0) cnt1++;
	if (xxxl % t != 0) cnt1++;
	
	cnt1 += s / t + m / t + l / t + xl / t + xxl / t + xxxl / t; 
	cout << cnt1 << '\n'; 
	cout << (s + m + l + xl + xxl + xxxl) / p << " " << (s + m + l + xl + xxl + xxxl) % p; 

	return 0;
}