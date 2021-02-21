#pragma onc
#include<iostream>
#ifndef _vehicle_h
#define _vehicle_h
class vehicle {
	int MaxSpeed;
	double Weight;
public:
	vehicle(int x, int y) :MaxSpeed(x), Weight(y) {
		std::cout << "calling constructor--vehicle..." << std::endl;
	}
	vehicle():MaxSpeed(0),Weight(0){}
	void Run() { std::cout << " vehicle departure" << std::endl; }
	void Stop() { std::cout << "vehicle stopped" << std::endl; }
	int getMaxSpeed() { return MaxSpeed; }
	int getWeight() { return Weight; }

};
#endif
