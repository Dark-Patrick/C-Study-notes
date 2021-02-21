#include<iostream>
#include<cmath>
using namespace std;
double sin(int n, double x) {
	double s, sum = 0;
	for (int i = 1; i <= n; i++) {
		s = 1;
		for (int j = 1; j <= i; j++)
			s += pow(sin(x), j);
		sum += s;
	}
	return sum;
}
int main() {
	int n;
	double x;
	cin >> n >> x;
	cout << sin(n,x) << endl;
	return 0;
}