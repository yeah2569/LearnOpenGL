// Demo.cpp : 定义应用程序的入口点。
//

#include "Demo.h"

#define MAX_LOADSTRING 100

// 全局变量:
HINSTANCE hInst;								// 当前实例
TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名
HGLRC ghRC;
HDC ghDC;
HWND ghWnd;

// 此代码模块中包含的函数的前向声明:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
bool initGL();
void destroyGL();


static void SetupPixelFormat(HDC hdc)
{
	int pixelFormat;

	PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),  // size
		1,                          // version
		PFD_SUPPORT_OPENGL |        // OpenGL window
		PFD_DRAW_TO_WINDOW |        // render to window
		PFD_DOUBLEBUFFER,           // support double-buffering
		PFD_TYPE_RGBA,              // color type
		32,                         // preferred color depth
		0, 0, 0, 0, 0, 0,           // color bits (ignored)
		0,                          // no alpha buffer
		0,                          // alpha bits (ignored)
		0,                          // no accumulation buffer
		0, 0, 0, 0,                 // accum bits (ignored)
		24,                         // depth buffer
		8,                          // no stencil buffer
		0,                          // no auxiliary buffers
		PFD_MAIN_PLANE,             // main layer
		0,                          // reserved
		0, 0, 0,                    // no layer, visible, damage masks
	};

	pixelFormat = ChoosePixelFormat(hdc,&pfd);
	SetPixelFormat(hdc,pixelFormat,&pfd);
}

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: 在此放置代码。
	MSG msg;
	HACCEL hAccelTable;
	bool bRet;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nLast;
	LARGE_INTEGER nNow;

	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nLast);

	// 初始化全局字符串
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_DEMO, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	bRet = initGL();
	if(!bRet) 
		destroyGL();

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DEMO));

	while (TRUE)
	{
		if (! PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// Get current time tick.
			//QueryPerformanceCounter(&nNow);

			// If it's the time to draw next frame, draw it, else sleep a while.
			//if (nNow.QuadPart - nLast.QuadPart > 69284)
			{
				//nLast.QuadPart = nNow.QuadPart;
				DrawScene();
				SwapBuffers(ghDC);			// 交换缓存 (双缓存)
			}
			//else
			{
				//Sleep(0);
			}
			continue;
		}

		if (WM_QUIT == msg.message)
		{
			// Quit message loop.
			break;
		}

		// Deal with windows message.
		if (! TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	// 主消息循环:
/*	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}*/

	return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目的: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DEMO));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_DEMO);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目的: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中

   ghWnd = CreateWindowEx( WS_EX_APPWINDOW | WS_EX_WINDOWEDGE,    // Extended Style For The Window
	   szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      0, 0, 500, 500, NULL, NULL, hInstance, NULL);

   if (!ghWnd)
   {
      return FALSE;
   }

   ShowWindow(ghWnd, nCmdShow);
  // UpdateWindow(ghWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的: 处理主窗口的消息。
//
//  WM_COMMAND	- 处理应用程序菜单
//  WM_PAINT	- 绘制主窗口
//  WM_DESTROY	- 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// 分析菜单选择:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: 在此添加任意绘图代码...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		destroyGL();
		PostQuitMessage(0);
		break;
	case WM_SIZE:
		ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

bool initGL()
{
	ghDC = GetDC(ghWnd);
	SetupPixelFormat(ghDC);

	ghRC = wglCreateContext(ghDC);
	wglMakeCurrent(ghDC,ghRC);

	GLenum GlewInitResult = glewInit();
	if (GLEW_OK != GlewInitResult)
	{
		MessageBox(NULL,_T("OpenGL error"),_T("error msg"),MB_OK);		
		return false;
	}

	ReSizeGLScene(500, 500);						// 设置透视 GL 屏幕
	return true;
}

void destroyGL()
{
	if (ghDC != NULL && ghRC != NULL)
	{
		// deselect rendering context and delete it
		wglMakeCurrent(ghDC, NULL);
		wglDeleteContext(ghRC);
	}
}

void DrawScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);			// 清除屏幕和深度缓存
	glLoadIdentity();							// 重置当前的模型观察矩阵
	glTranslatef(0.0f,0.0f,-6.0f);				// 左移 1.5 单位，并移入屏幕 6.0

	glBegin(GL_TRIANGLES);					// 开始绘制金字塔的各个面
	glColor3f(1.0f,0.0f,0.0f);			// 红色
	glVertex3f( 0.0f, 1.0f, 0.0f);			// 三角形的上顶点 (前侧面)
	glColor3f(0.0f,1.0f,0.0f);			// 绿色
	glVertex3f(-1.0f,-1.0f, 1.0f);			// 三角形的左下顶点 (前侧面)
	glColor3f(0.0f,0.0f,1.0f);			// 蓝色
	glVertex3f( 1.0f,-1.0f, 1.0f);			// 三角形的右下顶点 (前侧面)
	glColor3f(1.0f,0.0f,0.0f);			// 红色
	glVertex3f( 0.0f, 1.0f, 0.0f);			// 三角形的上顶点 (右侧面)
	glColor3f(0.0f,0.0f,1.0f);			// 蓝色
	glVertex3f( 1.0f,-1.0f, 1.0f);			// 三角形的左下顶点 (右侧面)
	glColor3f(0.0f,1.0f,0.0f);			// 绿色
	glVertex3f( 1.0f,-1.0f, -1.0f);			// 三角形的右下顶点 (右侧面)
	glColor3f(1.0f,0.0f,0.0f);			// 红色
	glVertex3f( 0.0f, 1.0f, 0.0f);			// 三角形的上顶点 (后侧面)
	glColor3f(0.0f,1.0f,0.0f);			// 绿色
	glVertex3f( 1.0f,-1.0f, -1.0f);			// 三角形的左下顶点 (后侧面)
	glColor3f(0.0f,0.0f,1.0f);			// 蓝色
	glVertex3f(-1.0f,-1.0f, -1.0f);			// 三角形的右下顶点 (后侧面)
	glColor3f(1.0f,0.0f,0.0f);			// 红色
	glVertex3f( 0.0f, 1.0f, 0.0f);			// 三角形的上顶点 (左侧面)
	glColor3f(0.0f,0.0f,1.0f);			// 蓝色
	glVertex3f(-1.0f,-1.0f,-1.0f);			// 三角形的左下顶点 (左侧面)
	glColor3f(0.0f,1.0f,0.0f);			// 绿色
	glVertex3f(-1.0f,-1.0f, 1.0f);			// 三角形的右下顶点 (左侧面)
	glEnd();						// 金字塔绘制结束
}

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)				// 重置OpenGL窗口大小
{
	if (height==0)								// 防止被零除
	{
		height=1;							// 将Height设为1
	}

	glViewport(0, 0, width, height);					// 重置当前的视口
	glMatrixMode(GL_PROJECTION);						// 选择投影矩阵
	glLoadIdentity();							// 重置投影矩阵

	// 设置视口的大小
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

	glMatrixMode(GL_MODELVIEW);						// 选择模型观察矩阵
	glLoadIdentity();							// 重置模型观察矩阵
}