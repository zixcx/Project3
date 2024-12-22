#include <windows.h>
#include "StartScreen.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

HINSTANCE g_hInst;
LPCWSTR lpszClass = L"Gomoku";

// ���� ȭ�� ���¸� ��Ÿ���� ���� (0: ���� ȭ��, 1: ���� ȭ��) 

int currentScreen = 0;

int APIENTRY WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpszCmdParam,
	_In_ int nCmdShow
) {
	HWND hWnd;
	MSG Message;
	WNDCLASSW WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&WndClass);

	hWnd = CreateWindow(
		lpszClass, lpszClass, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
		CW_USEDEFAULT, CW_USEDEFAULT, 850, 700,
		NULL, (HMENU)NULL, hInstance, NULL
	);

	if (!hWnd) {
		return 0;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&Message, NULL, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}

	return (int)Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) {
	switch (iMessage) {
	case WM_CREATE:
		InitializeStartScreen(hWnd);
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case 1: // ���� ���� ��ư
			currentScreen = 1; // ���� ȭ������ ��ȯ
			InitializeGame();
			InvalidateRect(hWnd, NULL, TRUE); // ȭ���� �ٽ� �׸����� ��û
			break;
		case 2: // ������ ���� ��ư
			MessageBox(hWnd, L"������ ���� ��ư Ŭ��", L"�˸�", MB_OK);
			break;
		case 3: // ���� ��ư
			PostQuitMessage(0);
			break;
		}
		break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		if (currentScreen == 0) {
			RenderStartScreen(hdc); // ���� ȭ�� �׸���
		}
		else {
			// ���� ȭ���� �׸��� ���� ����� ������� ����ϴ�.
			RECT rc;
			GetClientRect(hWnd, &rc);
			FillRect(hdc, &rc, (HBRUSH)GetStockObject(WHITE_BRUSH));

			RenderGame(hdc); // ���� ȭ�� �׸���
		}

		EndPaint(hWnd, &ps);
		break;
	}
	case WM_ERASEBKGND:
	{
		if (currentScreen == 1) { // ���� ȭ���� ���� ����� ����ϴ�.
			HDC hdc = (HDC)wParam;
			RECT rc;
			GetClientRect(hWnd, &rc);
			FillRect(hdc, &rc, (HBRUSH)GetStockObject(WHITE_BRUSH));
			return 1; // ����� �������� �ý��ۿ� �˸��ϴ�.
		}
		break;
	}
	case WM_LBUTTONDOWN:
		if (currentScreen == 0)
		{
			HandleStartScreenLButtonDown(hWnd, wParam, lParam);
		}
		else
		{
			HandleGameLButtonDown(hWnd, wParam, lParam);
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}
