//peotected�̳�
#include"point.h"
#ifndef _rectangle3_h
#define _rectangle3_h
class rectangle3 :protected point {
public:
	void initrectangle3(double x, double y, double w, double h) {
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
};
class derived :protected rectangle3 {
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
};
//point�еĳ�Ա������protected����ʽ������rectangle3��ɱ���������derived����
#endif
//˽�м̳кͱ����̳е�����
