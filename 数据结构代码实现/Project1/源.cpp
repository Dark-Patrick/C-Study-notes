#include<iostream>
#include<string>

struct Print {
	template<typename T>
	Print(T t) { ::std::cout << (t += 10); }
};
int main() {
	Print t(10);
	Print p(::std::string());//这是一个返回值为Print的函数
}