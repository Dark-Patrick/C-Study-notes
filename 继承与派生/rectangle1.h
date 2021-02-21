//public继承
#include"point.h"
#ifndef _rectangle1_h
#define _rectangle1_h
class rectangle1 :public point {
public:
	void initrectangle1(double x, double y, double w, double h) {
		initpoint(x, y);
		this->w = w;
		this->h = h;
		point::f = 10;//保护和私有的区别初见解
	}
	double geth()const { return h; }
	double getw()const { return w; }
private:
	double h, w;
};


#endif
