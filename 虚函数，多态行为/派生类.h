#pragma once
#include<iostream>
#include"����.h"
using namespace std;
#ifndef _Base1_h
#define _Base1_h
class Base2:public Base1 {
public:
	//void end(){} �޷���дfinal����
	void display()const {//�����ػ����е�ͬ���麯������virtual���Ӷ���
		cout << "Base2::display()" << endl;
	}

	virtual ~Base2()
	{
		cout << "Base2 destructor..." << endl;
	}

	virtual void text()const {
		cout << "Base2::test()" << endl;//���ǻ���Ĵ��麯��
	}
};


class Derived : public Base2 {
public:
	Derived() {
		p = new int(0);
	}
	 void display()const override{//override��c++11�±�׼�������麯����ͬ
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