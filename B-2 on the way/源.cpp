#include<iostream>
#include<Windows.h>
int main() {
	std::cout << "���ȸ�����Ҫ��ը������" <<'\n'<< std::endl;
	int i = 0;
	int count = 0;
	char name[100] = { 0 };
	std::cout << "�����ը�������ƣ������" << std::endl;
	::std::cin.get(name,100);
	
	std::cout << "�����ը����" << std::endl;

	scanf_s("%d", &i);
	HWND H = FindWindow(0, name);
	::std::cout << "�����ը�ļ��" << std::endl;
	::std::cin >> count;
	while (i--) {
		SendMessage(H, WM_PASTE, 0, 0);
		SendMessage(H, WM_KEYDOWN, VK_RETURN, 0);
		Sleep (count);
	}
	return 0;
}