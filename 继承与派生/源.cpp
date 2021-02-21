#include"rectangle1.h"
#include"rectangle2.h"
#include"protected.h"
#include<iostream>
using namespace std;
int main() {
	/*rectangle1 rect;
	rect.initrectangle1(2, 3, 20, 10);
	rect.move(3, 2);
	cout << "the data of rect(x,y,w,h):" << endl;
	cout << rect.getx() << ","
		<< rect.gety() << ","
		<< rect.getw() << ","
		<< rect.geth() << "," << endl;

	rectangle2 rect2;
	rect2.initrectangle2(2, 3, 20, 10);
	rect2.move(4, 2);
	cout << "the data of rect(x,y,w,h):" << endl;
	cout << rect2.getx() << ","
		<< rect2.gety() << ","
		<< rect2.getw() << ","
		<< rect2.geth() << "," << endl;
		*/
	derived2 rect3;
	rect3.initderived(10, 10, 2, 2);
	rect3.move(20,20);
	cout << "the data of rect(x,y,w,h):" << endl;
	cout << rect3.getx() << ","
		<< rect3.gety() << ","
		<< rect3.getw() << ","
		<< rect3.geth() << ","
		<<rect3.geth2() << endl;//³ö´íµã
	
	return 0;
}