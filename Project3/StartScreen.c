#include <windows.h>
#include "StartScreen.h"

HWND hButton1, hButton2, hButton3;

void InitializeStartScreen(HWND hWnd) {
	hButton1 = CreateWindow(
		L"BUTTON", L"1. 게임 시작",
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_FLAT,
		50, 120, 200, 30,
		hWnd, (HMENU)1, (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL
	);

	hButton2 = CreateWindow(
		L"BUTTON", L"2. 개발자 정보",
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_FLAT,
		50, 150, 200, 30,
		hWnd, (HMENU)2, (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL
	);

	hButton3 = CreateWindow(
		L"BUTTON", L"3. 종료",
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_FLAT,
		50, 210, 200, 30,
		hWnd, (HMENU)3, (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL
	);
}

void RenderStartScreen(HDC hdc) {
	// 여기서는 버튼이 이미 그려져 있으므로 시작 화면에 대한 추가적인 그리기가 필요하지 않습니다.
	// 필요한 경우 여기에 시작 화면에 대한 그리기 코드를 추가할 수 있습니다.
	// 예를 들어, 배경 이미지나 로고 등을 그릴 수 있습니다.
}

void HandleStartScreenLButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	// 시작 화면에서는 마우스 클릭을 처리할 필요가 없습니다. 버튼 클릭은 WM_COMMAND에서 처리됩니다.
	// 필요한 경우 여기에 마우스 클릭에 대한 처리 코드를 추가할 수 있습니다.
}