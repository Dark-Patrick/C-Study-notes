#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); //窗口过程

//窗口初始化（定义窗口的具体方式）
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
	static TCHAR lpszClassName[] = TEXT("窗口");  //窗口类名
   //TCHAR lpszTitle[] =TEXT( "My_Windows");  //窗口标题名
	wndclass.style = 0;				//窗口风格
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = WndProc;	//窗口过程函数地址
	wndclass.cbClsExtra = 0;  //窗口类无扩展
	wndclass.cbWndExtra = 0; //窗口实例无扩展
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);  //用箭头光标
	wndclass.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH));  //窗口背景色为白色
	wndclass.lpszMenuName = NULL;  //窗口无菜单
	wndclass.lpszClassName = lpszClassName; //窗口类名为"窗口"

	if (!RegisterClass(&wndclass))  //如果注册窗口类失败
	{
		MessageBeep(0); return FALSE;
	}
	hwnd = CreateWindow(
		lpszClassName,		 //窗口类名
		TEXT("MY WINDOWS"),		 //窗口实例的标题名
		WS_OVERLAPPEDWINDOW, //窗口的风格
		CW_USEDEFAULT,
		CW_USEDEFAULT,		 //以上2行表示窗口左上角坐标为默认值
		CW_USEDEFAULT,
		CW_USEDEFAULT,		 //以上2行表示窗口的高度和宽度为默认值
		NULL,				 //此窗口无父窗口
		NULL,				 //此窗口无主菜单
		hInstance,			 //创建此窗口的应用程序的当前句柄（即进程）
		NULL				 //不使用该值
	);
	ShowWindow(hwnd, nCmdShow); //显示窗口
	UpdateWindow(hwnd);			//绘制用户区（刷新用户区）
	while (GetMessage(&Msg, NULL, 0, 0))		//消息循环
	{
		TranslateMessage(&Msg);				//翻译消息
		DispatchMessage(&Msg);				//分发消息
	}
	return Msg.wParam;				//消息循环结束即程序结束将信息返回给系统
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
		DrawText(hdc, TEXT("这是李成浩创立的第一个窗口！"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &PS);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	
}
