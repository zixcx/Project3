#pragma once

#include <windows.h>

void InitializeGame();
void UpdateGame();
void RenderGame(HDC hdc);
void HandleGameLButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);