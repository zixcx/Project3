#pragma once

#include <windows.h>

void InitializeStartScreen(HWND hWnd);
void RenderStartScreen(HDC hdc);
void HandleStartScreenLButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);