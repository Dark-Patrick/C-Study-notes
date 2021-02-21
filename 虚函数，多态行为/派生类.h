#pragma once
#include<iostream>
#include"基类.h"
using namespace std;
#ifndef _Base1_h
#define _Base1_h
class Base2:public Base1 {
public:
	//void end(){} 无法重写final函数
	void display()const {//可隐藏基类中的同名虚函数，加virtual增加读性
		cout << "Base2::display()" << endl;
	}

	virtual ~Base2()
	{
		cout << "Base2 destructor..." << endl;
	}

	virtual void text()const {
		cout << "Base2::test()" << endl;//覆盖基类的纯虚函数
	}
};


class Derived : public Base2 {
public:
	Derived() {
		p = new int(0);
	}
	 void display()const override{//override：c++11新标准，保障虚函数相同
		 cout << "Derived::display()" << endl;
	 }
	virtual ~Derived()
	 {
		cout << "Dervied destructor..." << endl;
		delete p;
	 }

	virtual void text()const {
		cout << "Derived::test()" << endl;
	}
private:
	int* p;
};
#endif