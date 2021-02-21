//#include<iostream>
#ifndef _point_h
#define _point_h
class point {
public:
	void initpoint(double x = 0, double y = 0) {
		this->x = x;
		this->y = y;
	}
	void move(double offx, double offy) {
		x += offx;
		y += offy;
	}
	double getx()const { return x; }
	double gety()const { return y; }
private:
	double x, y;
protected:
	double f;
};
#endif

