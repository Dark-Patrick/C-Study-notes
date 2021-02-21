#include<iostream>
#include<list>
#include<string>
using namespace std;
int main() {
	string str = "hello and world and lichenghao and end";
	//str.replace(0,2, "and");
	cout << str << endl;
	int a = str.find("and",10);
	cout << a << endl;
}