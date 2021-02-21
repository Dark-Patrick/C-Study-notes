#include<iostream>
using namespace std;
int homework(double a) {
    int s;
	if (a -(int)a< 0.50)
		s = int(a);
	else
		s = int(a) + 1;
	return s;

}
int main() {
	double a;
	cin >> a;
	cout << homework(a) << endl;
	cout << sizeof(int) << " " << sizeof(double);
	return 0;
}