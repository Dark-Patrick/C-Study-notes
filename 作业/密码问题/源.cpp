#include<iostream>

using namespace std;

int main() {
	int a, sum, n;
	cin >> n;
	if (n >= 100 && n <= 999) {
		for (a = 100; a <= n; a++) {
			sum = (a % 10) * (a % 10) * (a % 10) + ((a / 10) % 10) * ((a / 10) % 10) * ((a / 10) % 10) + (a / 100) * (a / 100) * (a / 100);
			if (sum == a)
				cout << a << " ";
		}
	}
	else
		cout << "error" << endl;
	
	
	
		
	
}