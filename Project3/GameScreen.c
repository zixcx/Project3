#include "GameScreen.h"
#include <stdio.h>
#include <windows.h>

// 착수 정보를 저장하는 전역 배열
int placementRecord[15][15] = { 0 };

// 현재 차례를 나타내는 전역 변수 (FALSE = 흑돌, TRUE = 백돌)
static BOOL order = FALSE;

void InitializeGame() {
	// 게임 초기화 코드
	// 착수 정보 초기화
	for (int y = 0; y < 15; y++) {
		for (int x = 0; x < 15; x++) {
			placementRecord[y][x] = 0;
		}
	}
	order = FALSE; // 흑돌부터 시작
}

void UpdateGame() {
	// 게임 업데이트 코드
	printf("게임 업데이트\n");
}

void RenderGame(HDC hdc) {
	// 게임 렌더링 코드
	int squareSize = 40;
	int spacing = -1;
	POINT grid_start_pt = { 50, 50 };
	int radius = 20;

	for (int y = 0; y < 14; y++) {
		for (int x = 0; x < 14; x++) {
			Rectangle(hdc,
				grid_start_pt.x + (squareSize + spacing) * x,
				grid_start_pt.y + (squareSize + spacing) * y,
				grid_start_pt.x + (squareSize + spacing) * x + squareSize,
				grid_start_pt.y + (squareSize + spacing) * y + squareSize);
		}
	}

	for (int i = 0; i < 15; i++) {
		WCHAR ch1 = L'A' + i;
		TextOut(hdc, 50 + (squareSize + spacing) * i, 30, &ch1, 1);
		WCHAR number[3];
		swprintf(number, sizeof(number) / sizeof(WCHAR), L"%d", i + 1);
		TextOut(hdc, 30, 45 + (squareSize + spacing) * i, number, wcslen(number));
	}

	for (int y = 0; y < 15; y++) {
		for (int x = 0; x < 15; x++) {
			POINT crossPoint = {
				grid_start_pt.x + (squareSize + spacing) * x,
				grid_start_pt.y + (squareSize + spacing) * y
			};

			if (placementRecord[y][x] == 1) {
				SelectObject(hdc, GetStockObject(BLACK_BRUSH));
				Ellipse(hdc, crossPoint.x - radius, crossPoint.y - radius,
					crossPoint.x + radius, crossPoint.y + radius);
			}
			else if (placementRecord[y][x] == 2) {
				SelectObject(hdc, GetStockObject(WHITE_BRUSH));
				Ellipse(hdc, crossPoint.x - radius, crossPoint.y - radius,
					crossPoint.x + radius, crossPoint.y + radius);
				SelectObject(hdc, GetStockObject(BLACK_PEN));
				Ellipse(hdc, crossPoint.x - radius, crossPoint.y - radius,
					crossPoint.x + radius, crossPoint.y + radius);
			}
		}
	}
}

void HandleGameLButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	// 게임 화면에서 클릭 처리 코드
	static POINT hoverPos = { -1, -1 };
	int squareSize = 40;
	int spacing = -1;
	POINT grid_start_pt = { 50, 50 };
	int radius = 20;

	POINT mpt;
	mpt.x = LOWORD(lParam);
	mpt.y = HIWORD(lParam);

	for (int y = 0; y < 15; y++) {
		for (int x = 0; x < 15; x++) {
			POINT crossPoint = {
				grid_start_pt.x + (squareSize + spacing) * x,
				grid_start_pt.y + (squareSize + spacing) * y
			};

			if ((crossPoint.x - radius < mpt.x && crossPoint.x + radius > mpt.x) &&
				(crossPoint.y - radius < mpt.y && crossPoint.y + radius > mpt.y)) {
				hoverPos.x = x;
				hoverPos.y = y;
				break;
			}
		}
		if (hoverPos.x != -1 && hoverPos.y != -1) break;
	}

	if (hoverPos.x != -1 && hoverPos.y != -1) {
		int x = hoverPos.x;
		int y = hoverPos.y;

		if (placementRecord[y][x] == 0) {
			// 착수 가능
			placementRecord[y][x] = order ? 2 : 1;
			printf("착수: %s - %c%d\n", order ? "백돌" : "흑돌", 'A' + x, y + 1);

			order = !order;
			InvalidateRect(hWnd, NULL, FALSE);
		}
	}
}
