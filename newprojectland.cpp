

#include <windows.h>
#include <stdio.h>
#include <GL/gl.h>

#include "framework.h"
#include "newprojectland.h"

#pragma comment(lib, "opengl32.lib")

float myx = 0.f;

HWND hOGLWnd = NULL;
HGLRC hrc0 = NULL;	//	two render contexts to flip
HGLRC hrc1 = NULL;

#define MAX_LOADSTRING 100
HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING]; 
WCHAR szWindowClass[MAX_LOADSTRING];

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_NEWPROJECTLAND, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_NEWPROJECTLAND));

    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}


ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_NEWPROJECTLAND));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_NEWPROJECTLAND);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance;

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   hOGLWnd = hWnd;
   HDC hDC = ::GetDC(hOGLWnd);

   // Create OpenGL context
   DWORD pixelFormatFlags = PFD_SUPPORT_OPENGL | PFD_SUPPORT_COMPOSITION | PFD_GENERIC_ACCELERATED | PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER;
   PIXELFORMATDESCRIPTOR pfd = {
	 sizeof(PIXELFORMATDESCRIPTOR),
	 1,
	 pixelFormatFlags,         //Flags
	 PFD_TYPE_RGBA,            //The kind of framebuffer. RGBA or palette.
	 32,                       //Colordepth of the framebuffer.
	 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	 24,                       //Number of bits for the depthbuffer
	 8,                        //Number of bits for the stencilbuffer
	 0,                        //Number of Aux buffers in the framebuffer.
	 PFD_MAIN_PLANE,
	 0, 0, 0, 0
   };
   int pixelFormat = ::ChoosePixelFormat(hDC, &pfd);
   ::SetPixelFormat(hDC, pixelFormat, &pfd);

   hrc0 = ::wglCreateContext(hDC);
   hrc1 = ::wglCreateContext(hDC);
   ::wglMakeCurrent(hDC, hrc1);

   // release device context
//   ::ReleaseDC(hOGLWnd, hDC);

   ::ShowWindow(hOGLWnd, SW_SHOWDEFAULT);
   //ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

void display(void) {
	RECT clientRect;
	::GetClientRect(hOGLWnd, &clientRect);
	glViewport(0, 0, clientRect.right - clientRect.left, clientRect.bottom - clientRect.top);
	glClearColor(1.0f, 0.5f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);  // Red color
	glVertex2f(-0.9, -0.9);   // Vertex 1
	glColor3f(0.0, 1.0, 0.0);  // Green color
	glVertex2f(0.9, -0.9);    // Vertex 2
	glColor3f(0.0, 0.0, 1.0);  // Blue color
	glVertex2f(myx, 0.9);     // Vertex 3
	glEnd();

	glFlush();

	HDC hDC = ::GetDC(hOGLWnd);
	::SwapBuffers(hDC);
	::ReleaseDC(hOGLWnd, hDC);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
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
        }
        break;
	case WM_CREATE: {
		SetTimer(hWnd, 1, 10, NULL);
	}	break;
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
		myx += .01f;	if (myx > 1.f) myx -= 2.f;
		display();
        EndPaint(hWnd, &ps);
    }	break;
	case WM_TIMER: {
		InvalidateRgn(hWnd, 0, 0);	UpdateWindow(hWnd);
	}   break;
    case WM_DESTROY:
		if (HDC currentDC = ::wglGetCurrentDC()) ::wglMakeCurrent(currentDC , NULL);
		::DestroyWindow(hOGLWnd);
		::wglDeleteContext(hrc0);
		::wglDeleteContext(hrc1);
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

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
