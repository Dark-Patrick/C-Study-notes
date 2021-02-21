#pragma once
#ifndef employee_h_
#define employee_h_
#include<iostream>_
using namespace std;

class Employee {
	const char* name ;
	const char* address;
	const char* city;
	const char* code;
public:
	Employee(const char* n="",const char* add="",const char* ct="",const char* cd="") :name(n), address(add), city(ct), code(cd) {}
	void display() {
		cout << "name:   " << name << endl;
		cout << "address:" << address << endl;
		cout << "city:   " << city << endl;
		cout << "code:   " << code << endl;
	}
	void change_name(const char* nm)
		{
			name = nm; 
		}
	void setaddress(const char* n) { address = n; }

	
	
};
#endif
