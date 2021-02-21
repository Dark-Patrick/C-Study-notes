#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); //���ڹ���

//���ڳ�ʼ�������崰�ڵľ��巽ʽ��
int WINAPI WinMain
(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
)
//int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevlnst, LPSTR lpsCmdLine, int nCmdShow)
{
	HWND hwnd;
	MSG Msg;
	WNDCLASS wndclass;
	static TCHAR lpszClassName[] = TEXT("����");  //��������
   //TCHAR lpszTitle[] =TEXT( "My_Windows");  //���ڱ�����
	wndclass.style = 0;				//���ڷ��
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = WndProc;	//���ڹ��̺�����ַ
	wndclass.cbClsExtra = 0;  //����������չ
	wndclass.cbWndExtra = 0; //����ʵ������չ
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);  //�ü�ͷ���
	wndclass.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH));  //���ڱ���ɫΪ��ɫ
	wndclass.lpszMenuName = NULL;  //�����޲˵�
	wndclass.lpszClassName = lpszClassName; //��������Ϊ"����"

	if (!RegisterClass(&wndclass))  //���ע�ᴰ����ʧ��
	{
		MessageBeep(0); return FALSE;
	}
	hwnd = CreateWindow(
		lpszClassName,		 //��������
		TEXT("MY WINDOWS"),		 //����ʵ���ı�����
		WS_OVERLAPPEDWINDOW, //���ڵķ��
		CW_USEDEFAULT,
		CW_USEDEFAULT,		 //����2�б�ʾ�������Ͻ�����ΪĬ��ֵ
		CW_USEDEFAULT,
		CW_USEDEFAULT,		 //����2�б�ʾ���ڵĸ߶ȺͿ��ΪĬ��ֵ
		NULL,				 //�˴����޸�����
		NULL,				 //�˴��������˵�
		hInstance,			 //�����˴��ڵ�Ӧ�ó���ĵ�ǰ����������̣�
		NULL				 //��ʹ�ø�ֵ
	);
	ShowWindow(hwnd, nCmdShow); //��ʾ����
	UpdateWindow(hwnd);			//�����û�����ˢ���û�����
	while (GetMessage(&Msg, NULL, 0, 0))		//��Ϣѭ��
	{
		TranslateMessage(&Msg);				//������Ϣ
		DispatchMessage(&Msg);				//�ַ���Ϣ
	}
	return Msg.wParam;				//��Ϣѭ�������������������Ϣ���ظ�ϵͳ
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT PS;
	RECT rect;
	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &PS);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, TEXT("������ɺƴ����ĵ�һ�����ڣ�"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &PS);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	
}
