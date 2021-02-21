#include<iostream>
#include<Windows.h>
int main() {
	std::cout << "请先复制所要轰炸的内容" <<'\n'<< std::endl;
	int i = 0;
	int count = 0;
	char name[100] = { 0 };
	std::cout << "输入轰炸对象名称（句柄）" << std::endl;
	::std::cin.get(name,100);
	
	std::cout << "输入轰炸次数" << std::endl;

	scanf_s("%d", &i);
	HWND H = FindWindow(0, name);
	::std::cout << "输入轰炸的间隔" << std::endl;
	::std::cin >> count;
	while (i--) {
		SendMessage(H, WM_PASTE, 0, 0);
		SendMessage(H, WM_KEYDOWN, VK_RETURN, 0);
		Sleep (count);
	}
	return 0;
}