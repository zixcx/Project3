#include <windows.h>
#include "StartScreen.h"

HWND hButton1, hButton2, hButton3;

void InitializeStartScreen(HWND hWnd) {
	hButton1 = CreateWindow(
		L"BUTTON", L"1. ���� ����",
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_FLAT,
		50, 120, 200, 30,
		hWnd, (HMENU)1, (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL
	);

	hButton2 = CreateWindow(
		L"BUTTON", L"2. ������ ����",
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_FLAT,
		50, 150, 200, 30,
		hWnd, (HMENU)2, (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL
	);

	hButton3 = CreateWindow(
		L"BUTTON", L"3. ����",
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_FLAT,
		50, 210, 200, 30,
		hWnd, (HMENU)3, (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL
	);
}

void RenderStartScreen(HDC hdc) {
	// ���⼭�� ��ư�� �̹� �׷��� �����Ƿ� ���� ȭ�鿡 ���� �߰����� �׸��Ⱑ �ʿ����� �ʽ��ϴ�.
	// �ʿ��� ��� ���⿡ ���� ȭ�鿡 ���� �׸��� �ڵ带 �߰��� �� �ֽ��ϴ�.
	// ���� ���, ��� �̹����� �ΰ� ���� �׸� �� �ֽ��ϴ�.
}

void HandleStartScreenLButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	// ���� ȭ�鿡���� ���콺 Ŭ���� ó���� �ʿ䰡 �����ϴ�. ��ư Ŭ���� WM_COMMAND���� ó���˴ϴ�.
	// �ʿ��� ��� ���⿡ ���콺 Ŭ���� ���� ó�� �ڵ带 �߰��� �� �ֽ��ϴ�.
}