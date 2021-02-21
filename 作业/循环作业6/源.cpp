#include<iostream>
using namespace std;
int main() {
	double e, s, a ;
	int i = 1;
	cin >> e;
	s = 0;
	while (1.0 / i > e) {
		a = 1.0 / i;
		
		s = (i % 8 == 1) ? s + a : s - a;
		i+=4;
	}
	cout <<  s;
}
