#include<iostream>
#include"����.h"
#include"������.h"
using namespace std;
void fun1(Base1 * ptr){
		ptr->display();
	}
void fun2(Base1* b) {
	delete[] b;
}
void text(Base1* a) {
	a->text();
}
int main() {
	//Base1 base1;�����࣬���ɶ������
	Base2 base2;
	Derived derived;
	
	fun1(&base2);
	fun1(&derived);
	text(&base2);
	Base1* b = new Base2();
	fun2(b); 
	return 0;
	
}