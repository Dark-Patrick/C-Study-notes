#include<iostream>
using namespace std;
int a = 10;

void fun() {
	a = 100;
	cout << a << endl;
}
int main() {
	fun();
	cout << a << endl;
}