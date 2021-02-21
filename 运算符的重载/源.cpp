#include<iostream>
#include"双目complex.h"
#include"单目clock.h"
using namespace std;

int main() {
	Complex a(2.0,1.2), b(1.0,2.3);
	a = a + b;
	a.display();
	a = 3 + a;
	a.display();
	cout << a <<b<< endl;//与display对比两者的差别
	//ostream,输出流类库，cout为其定义好的对象，向屏幕输出
	//双目

	Clock myclock(23, 59, 59);
	cout << "First time output";
	myclock.showtime();
	cout << "Show myclock++";
	(myclock++).showtime();
	cout << "Show ++myclock";
	(++myclock).showtime();
	return 0;
	//单目
}