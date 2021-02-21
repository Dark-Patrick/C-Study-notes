#include<iostream>
using namespace std;
int main() {
	char a;
	int s;
	cin >> a;
	s = 0;
	while (a != '0') {
		s += a;
		cin >> a;
	}
	cout << s << endl;

}