//private继承
#include"point.h"
#ifndef _rectangle2_h
#define _rectangle2_h
class rectangle2:private point {
public:
	void initrectangle2(double x, double y, double w, double h) {
		point::initpoint(x, y);
		this->w = w;
		this->h = h;
	}
	void move(double offx, double offy) {
		point::move(offx, offy);
	}
	double geth()const { return h; }
	double getw()const { return w; }
	double getx()const { return point::getx(); }
	double gety()const { return point::gety(); }
private:
	double w, h;
};
class derived2 :protected rectangle2 {
public:
	void initderived(double x, double y, double w, double h) {
		initrectangle2(x, y, w, h);
		this->w = w;
		this->h = h;
		
	}
	void move(double offx, double offy) {
		rectangle2::move(offx, offy);
	}
	double geth()const { return h; }
	double getw()const { return w; }
	double getx()const { return rectangle2::getx(); }
	double gety()const { return rectangle2::gety(); }
	double geth2()const { return rectangle2::geth(); }
private:
	double w, h;
};
/*class derivederr :public rectangle2 {
public:
	void initderived(double x, double y, double w, double h) {
		initpoint(x, y);
		this->w = w;
		this->h = h;
	}
	void move(double offx, double offy) {
		point::move(offx, offy);
	}
	double geth()const { return h; }
	double getw()const { return w; }
	double getx()const { return point::getx(); }
	double gety()const { return point::gety(); }
private:
	double w, h;
};*/
//initpoint，point::move 以私有形式出现在派生类rectangle2中，rectangle2的派生类成员函数不可访问
#endif
//私有继承和保护继承的区别？