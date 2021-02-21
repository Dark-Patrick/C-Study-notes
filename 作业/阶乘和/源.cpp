#include<iostream>
using namespace std;
int main(){
	int n, i, j, sum, x;
	
	cin >> n;
	sum = 0;
	
	for (i = 1; i <= n; i++) {
		x = 1;
		for (j = 1; j <= i; j++) {
			
			x *= j;
		}
		sum += x;
}
	cout << double(sum) << endl;
}