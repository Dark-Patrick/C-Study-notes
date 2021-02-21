#pragma once
#include<iostream>
using namespace std;
class Complex {
public:
	Complex(double r=0.0,double i=0.0):real(r),imag(i){}
	Complex operator +(const Complex& c2)const {
		return Complex(real + c2.real, imag + c2.imag);
	}
	Complex operator -(const Complex& c2)const {
		return  Complex(real - c2.real, imag - c2.imag);
	}
	void display()const {
		cout << "(" << real << "," << imag << ")" << endl;
	}
    friend Complex operator +(int a, const Complex& c2);
	friend Complex operator -(int a, const Complex& c2);
	friend ostream& operator <<(ostream& out, const Complex& c);
private:
	double real;
	double imag;
};


//运算符重载为非成员函数
Complex operator +(int a,const Complex& c2) {
	return Complex(c2.real + a, c2.imag);
}
Complex operator -(int a,const Complex& c2) {
	return  Complex(c2.real - a, c2.imag);
}//需调用类中的私有成员函数，用friend 的形式，可提高效率
ostream& operator <<(ostream&out,const Complex&c){
	out << "(" << c.real << "," << c.imag << ")";
	return out;
}//理解返回值，和输出流对象，十一章