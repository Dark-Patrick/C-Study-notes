#include<iostream>
#include"˫Ŀcomplex.h"
#include"��Ŀclock.h"
using namespace std;

int main() {
	Complex a(2.0,1.2), b(1.0,2.3);
	a = a + b;
	a.display();
	a = 3 + a;
	a.display();
	cout << a <<b<< endl;//��display�Ա����ߵĲ��
	//ostream,�������⣬coutΪ�䶨��õĶ�������Ļ���
	//˫Ŀ

	Clock myclock(23, 59, 59);
	cout << "First time output";
	myclock.showtime();
	cout << "Show myclock++";
	(myclock++).showtime();
	cout << "Show ++myclock";
	(++myclock).showtime();
	return 0;
	//��Ŀ
}