#include<iostream>
using namespace std;
int main() {
	int n, max, i;
	
	cin >> n;
	max = n % 10;
	for (; n > 0;n= n / 10) {
		i = n % 10;
		if (i > max)
			max = i;


	}
	cout << max << endl;
	return 0;
}