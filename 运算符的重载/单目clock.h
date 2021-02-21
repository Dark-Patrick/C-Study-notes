#pragma once
#include<iostream>
using namespace std;
class Clock {
public:
	Clock(int hour = 0, int minute = 0, int second = 0) {
		if (0 <= hour && hour < 24 && 0 <= minute && minute < 60 && 0 <= second && second < 60)
		{
			this->hour = hour;
			this->minute = minute;
			this->second = second;
		}
		else
			cout << "time error!" << endl;
	}
	void showtime()const {
		cout << hour << ":" << minute << ":" << second << endl;
	}
	Clock& operator ++();
	Clock operator ++(int);
private:
	int hour, minute, second;
};
//前置++
Clock& Clock::operator++() {
	second++;
	if (second >= 60) {
		second -= 60; minute++;
		if (minute >= 60) {
			minute -= 60; hour = (hour + 1) % 24;
		}
	}
	return *this;
}//返回值是当前的对象

Clock Clock::operator++(int) {
	//注意形参表中的整型参数
	Clock old = *this;//将当前的对象参数传给新定义对象old
	++ *this;//调用前置“++”运算符，防止两种算法的方式不同
	return old;//将自增前的副本作为返回值，this自增
}

