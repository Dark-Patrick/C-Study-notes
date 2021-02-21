#pragma once
#include<iostream>
#include"»ùÀà.h"
class bicycle : virtual protected vehicle {
public:
	bicycle(int a) :Height(a) {}
	bicycle():Height(0){}
	int Height;
};
class motorcar :virtual protected vehicle {
public:
	motorcar(int a) :SeatNum(a) {}
	motorcar():SeatNum(0){}
	
	int SeatNum;
	
};
class motorcycle :protected bicycle, protected motorcar {
public:
	motorcycle(int m, double w, int h, int s) :vehicle(m, w),bicycle(h),motorcar(s) {
		std::cout << "calling constructor--motorcycle..." << std::endl;
	}
	void show() {
		std::cout << getMaxSpeed() <<"  "
			<< getWeight()<<"  "
			<< Height<<"  "
			<< SeatNum <<"  "
			<< std::endl;
	}
	
	~motorcycle()
	{
		std::cout << "deleting..." << std::endl;
	}
};