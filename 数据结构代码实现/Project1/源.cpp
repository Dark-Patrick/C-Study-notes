#include<iostream>
#include<string>

struct Print {
	template<typename T>
	Print(T t) { ::std::cout << (t += 10); }
};
int main() {
	Print t(10);
	Print p(::std::string());//����һ������ֵΪPrint�ĺ���
}