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
//ǰ��++
Clock& Clock::operator++() {
	second++;
	if (second >= 60) {
		second -= 60; minute++;
		if (minute >= 60) {
			minute -= 60; hour = (hour + 1) % 24;
		}
	}
	return *this;
}//����ֵ�ǵ�ǰ�Ķ���

Clock Clock::operator++(int) {
	//ע���βα��е����Ͳ���
	Clock old = *this;//����ǰ�Ķ�����������¶������old
	++ *this;//����ǰ�á�++�����������ֹ�����㷨�ķ�ʽ��ͬ
	return old;//������ǰ�ĸ�����Ϊ����ֵ��this����
}

