#pragma once
#include<iostream>
using namespace std;
#ifndef _Base_h
#define _Base_h
class Base1 {
public:
	virtual void end() final{}//final���治���ٸ���  c++11�¼�
	virtual void text()const = 0;//���󣺴��麯���������Ϊ�����࣬���ܶ���base1�Ķ���
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