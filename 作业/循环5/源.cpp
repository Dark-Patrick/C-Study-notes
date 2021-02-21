#include<iostream>
using namespace std;
int main() {
	int n, a, s, i,c;
	cin >> a >> n;
	s = 0;
	c = a;
	for (i = 1; i <= n; i++) {
		s += a;
		a = a * 10 + c;
	}
	cout << s << endl;

}