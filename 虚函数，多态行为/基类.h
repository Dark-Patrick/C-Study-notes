#pragma once
#include<iostream>
using namespace std;
#ifndef _Base_h
#define _Base_h
class Base1 {
public:
	virtual void end() final{}//final表面不可再覆盖  c++11新加
	virtual void text()const = 0;//抽象：纯虚函数，此类变为抽象类，不能定义base1的对象
	virtual void display() const;
	virtual ~Base1()
	{
		cout << "Base1 destructor..." << endl;
	}
};
void Base1::display()const {
	cout << "Base1::display()" << endl;
}
#endif