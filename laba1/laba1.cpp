// laba1.cpp : Определяет точку входа для приложения.
//

#include "stdafx.h"
#include "laba1.h"
#include <windows.h>
#include<iostream>


using namespace std;

HINSTANCE HInst;
HWND hMainWnd; // создаём дескриптор будущего окошка
HWND hGreenScroll;
HWND vGreenScroll;

HWND buttonFile;
HWND buttonBackground;
HWND buttonImage;
HWND buttonAbout;
HWND buttonImage1;
HWND buttonImage2;
HWND buttonImage3;
HWND buttonBack;

HWND buttonExit;
HWND buttonShow;
HWND buttonScale;
HWND buttonScroll;

HMENU hPopMenuImage;
HMENU hPopMenuShow;


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR mainMessage[] = L"Какой то-текст!"; // строка с сообщением

int image = 0;
int mode = 0;
int menuPage = 0;

int nxPos = 0;
int nyPos = 0;


void createButtons()
{
	RECT rect = { 0 };
	GetWindowRect(hMainWnd, &rect);

	buttonFile = CreateWindow(L"BUTTON", L"File", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,

		(rect.right - rect.left) / 2 - 100,         // starting x position 
		(rect.bottom - rect.top) / 4,         // starting y position 
		100,        // button width 
		30,        // button height 
		hMainWnd,       // parent window 
		(HMENU)1010,       // No menu 
		(HINSTANCE)GetWindowLong(hMainWnd, GWL_HINSTANCE),
		NULL);

	buttonBackground = CreateWindow(L"BUTTON", L"Background", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,

		(rect.right - rect.left) / 2 - 100,         // starting x position 
		(rect.bottom - rect.top) / 4 + 60,         // starting y position 
		100,        // button width 
		30,        // button height 
		hMainWnd,       // parent window 
		(HMENU)1011,       // No menu 
		(HINSTANCE)GetWindowLong(hMainWnd, GWL_HINSTANCE),
		NULL);

	buttonImage = CreateWindow(L"BUTTON", L"Image", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,

		(rect.right - rect.left) / 2 - 100,         // starting x position 
		(rect.bottom - rect.top) / 4 + 120,         // starting y position 
		100,        // button width 
		30,        // button height 
		hMainWnd,       // parent window 
		(HMENU)1012,       // No menu 
		(HINSTANCE)GetWindowLong(hMainWnd, GWL_HINSTANCE),
		NULL);

	buttonAbout = CreateWindow(L"BUTTON", L"About", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,

		(rect.right - rect.left) / 2 - 100,         // starting x position 
		(rect.bottom - rect.top) / 4 + 180,         // starting y position 
		100,        // button width 
		30,        // button height 
		hMainWnd,       // parent window 
		(HMENU)1013,       // No menu 
		(HINSTANCE)GetWindowLong(hMainWnd, GWL_HINSTANCE),
		NULL);

	buttonBack = CreateWindow(L"BUTTON", L"Back", WS_CHILD | BS_DEFPUSHBUTTON,

		(rect.right - rect.left) / 2 - 100,         // starting x position 
		(rect.bottom - rect.top) / 4 + 240,         // starting y position 
		100,        // button width 
		30,        // button height 
		hMainWnd,       // parent window 
		(HMENU)1000,       // No menu 
		(HINSTANCE)GetWindowLong(hMainWnd, GWL_HINSTANCE),
		NULL);

	buttonImage1 = CreateWindow(L"BUTTON", L"Image1", WS_CHILD | BS_DEFPUSHBUTTON,

		(rect.right - rect.left) / 2 - 100,         // starting x position 
		(rect.bottom - rect.top) / 4,         // starting y position 
		100,        // button width 
		30,        // button height 
		hMainWnd,       // parent window 
		(HMENU)1004,       // No menu 
		(HINSTANCE)GetWindowLong(hMainWnd, GWL_HINSTANCE),
		NULL);

	buttonImage2 = CreateWindow(L"BUTTON", L"Image2", WS_CHILD | BS_DEFPUSHBUTTON,

		(rect.right - rect.left) / 2 - 100,         // starting x position 
		(rect.bottom - rect.top) / 4 + 60,         // starting y position 
		100,        // button width 
		30,        // button height 
		hMainWnd,       // parent window 
		(HMENU)1005,       // No menu 
		(HINSTANCE)GetWindowLong(hMainWnd, GWL_HINSTANCE),
		NULL);

	buttonImage3 = CreateWindow(L"BUTTON", L"Image3", WS_CHILD | BS_DEFPUSHBUTTON,

		(rect.right - rect.left) / 2 - 100,         // starting x position 
		(rect.bottom - rect.top) / 4 + 120,         // starting y position 
		100,        // button width 
		30,        // button height 
		hMainWnd,       // parent window 
		(HMENU)1006,       // No menu 
		(HINSTANCE)GetWindowLong(hMainWnd, GWL_HINSTANCE),
		NULL);

	buttonExit = CreateWindow(L"BUTTON", L"Exit", WS_CHILD | BS_DEFPUSHBUTTON,

		(rect.right - rect.left) / 2 - 100,         // starting x position 
		(rect.bottom - rect.top) / 4,         // starting y position 
		100,        // button width 
		30,        // button height 
		hMainWnd,       // parent window 
		(HMENU)1001,       // No menu 
		(HINSTANCE)GetWindowLong(hMainWnd, GWL_HINSTANCE),
		NULL);

	buttonShow = CreateWindow(L"BUTTON", L"Show", WS_CHILD | BS_DEFPUSHBUTTON,

		(rect.right - rect.left) / 2 - 100,         // starting x position 
		(rect.bottom - rect.top) / 4,         // starting y position 
		100,        // button width 
		30,        // button height 
		hMainWnd,       // parent window 
		(HMENU)1111,       // No menu 
		(HINSTANCE)GetWindowLong(hMainWnd, GWL_HINSTANCE),
		NULL);

	buttonScroll = CreateWindow(L"BUTTON", L"Scroll", WS_CHILD | BS_DEFPUSHBUTTON,

		(rect.right - rect.left) / 2 - 100,         // starting x position 
		(rect.bottom - rect.top) / 4,         // starting y position 
		100,        // button width 
		30,        // button height 
		hMainWnd,       // parent window 
		(HMENU)1002,       // No menu 
		(HINSTANCE)GetWindowLong(hMainWnd, GWL_HINSTANCE),
		NULL);

	buttonScale = CreateWindow(L"BUTTON", L"Scale", WS_CHILD | BS_DEFPUSHBUTTON,

		(rect.right - rect.left) / 2 - 100,         // starting x position 
		(rect.bottom - rect.top) / 4 + 60,         // starting y position 
		100,        // button width 
		30,        // button height 
		hMainWnd,       // parent window 
		(HMENU)1003,       // No menu 
		(HINSTANCE)GetWindowLong(hMainWnd, GWL_HINSTANCE),
		NULL);
}
void DrawBitmap(HDC hdc, HBITMAP hBitmap, int xStart, int yStart)
{
	BITMAP bm;
	HDC hdcMem;
	DWORD dwSize;
	POINT ptSize, ptOrg;

	RECT rect = { 0 };
	GetWindowRect(hMainWnd, &rect);

	hdcMem = CreateCompatibleDC(hdc);

	SelectObject(hdcMem, hBitmap);
	SetMapMode(hdcMem, GetMapMode(hdc));

	GetObject(hBitmap, sizeof(BITMAP), (LPVOID)&bm);

	ptSize.x = bm.bmWidth;
	ptSize.y = bm.bmHeight;

	DPtoLP(hdc, &ptSize, 1);

	ptOrg.x = 0;
	ptOrg.y = 0;

	DPtoLP(hdcMem, &ptOrg, 1);

	POINT newSize;
	newSize.x=rect.right-rect.left;
	newSize.y= rect.bottom- rect.top;

	
	if (mode == 0)
	{
		SetScrollRange(hGreenScroll, SB_CTL, 0, ptSize.x- newSize.x, FALSE);
		SetScrollRange(vGreenScroll, SB_CTL, 0, ptSize.y- newSize.y, FALSE);

		BitBlt(
			hdc, xStart-nxPos, yStart-nyPos,
			ptSize.x, ptSize.y,
			hdcMem, ptOrg.x, ptOrg.y,
			SRCCOPY
		);
	}
	else
	{
		StretchBlt(
			hdc, xStart, yStart, newSize.x, newSize.y,
			hdcMem, ptOrg.x, ptOrg.y,
			ptSize.x, ptSize.y, SRCCOPY
		);
	}
	
	


	DeleteDC(hdcMem);
}

void drawScrols()
{
	RECT rect = { 0 };
	GetWindowRect(hMainWnd, &rect);
	
	SetWindowPos(hGreenScroll, NULL,0, rect.bottom - rect.top - 74, rect.right - rect.left - 30, 15,NULL);
	SetWindowPos(vGreenScroll, NULL, rect.right - rect.left - 30, 0, 15, rect.bottom - rect.top - 74, NULL);

}

void drawButtons()
{
	

	RECT rect = { 0 };
	GetWindowRect(hMainWnd, &rect);

	if(menuPage!=0)
		ShowWindow(buttonBack, SW_SHOW);
	else
		ShowWindow(buttonBack, SW_HIDE);

	

	if (menuPage == 0)
	{
		ShowWindow(buttonFile, SW_SHOW);
		ShowWindow(buttonBackground, SW_SHOW);
		ShowWindow(buttonImage, SW_SHOW);
		ShowWindow(buttonAbout, SW_SHOW);
	}
	else
	{
		ShowWindow(buttonFile, SW_HIDE);
		ShowWindow(buttonBackground, SW_HIDE);
		ShowWindow(buttonImage, SW_HIDE);
		ShowWindow(buttonAbout, SW_HIDE);
	}

	if (menuPage == 1)
	{
		ShowWindow(buttonExit, SW_SHOW);
	}
	else
	{
		ShowWindow(buttonExit, SW_HIDE);
	}

	if (menuPage == 2)
	{
		ShowWindow(buttonShow, SW_SHOW);
	}
	else
	{
		ShowWindow(buttonShow, SW_HIDE);
	}


	if (menuPage == 3)
	{
		ShowWindow(buttonImage1, SW_SHOW);
		ShowWindow(buttonImage2, SW_SHOW);
		ShowWindow(buttonImage3, SW_SHOW);
	}
	else
	{
		ShowWindow(buttonImage1, SW_HIDE);
		ShowWindow(buttonImage2, SW_HIDE);
		ShowWindow(buttonImage3, SW_HIDE);
	}

	
	
	if (menuPage == 5)
	{
		ShowWindow(buttonScroll, SW_SHOW);
		ShowWindow(buttonScale, SW_SHOW);
	}
	else
	{
		ShowWindow(buttonScroll, SW_HIDE);
		ShowWindow(buttonScale, SW_HIDE);
	}

	SetWindowPos(buttonFile, NULL, (rect.right - rect.left) / 2 - 100,(rect.bottom - rect.top) / 4 ,100, 30, NULL);
	SetWindowPos(buttonBackground, NULL, (rect.right - rect.left) / 2 - 100, (rect.bottom - rect.top) / 4+60, 100, 30, NULL);
	SetWindowPos(buttonImage, NULL, (rect.right - rect.left) / 2 - 100, (rect.bottom - rect.top) / 4+120, 100, 30, NULL);
	SetWindowPos(buttonAbout, NULL, (rect.right - rect.left) / 2 - 100, (rect.bottom - rect.top) / 4+180, 100, 30, NULL);
	SetWindowPos(buttonBack, NULL, (rect.right - rect.left) / 2 - 100, (rect.bottom - rect.top) / 4 + 240, 100, 30, NULL);

	SetWindowPos(buttonImage1, NULL, (rect.right - rect.left) / 2 - 100, (rect.bottom - rect.top) / 4, 100, 30, NULL);
	SetWindowPos(buttonImage2, NULL, (rect.right - rect.left) / 2 - 100, (rect.bottom - rect.top) / 4 + 60, 100, 30, NULL);
	SetWindowPos(buttonImage3, NULL, (rect.right - rect.left) / 2 - 100, (rect.bottom - rect.top) / 4 + 120, 100, 30, NULL);

	SetWindowPos(buttonExit, NULL, (rect.right - rect.left) / 2 - 100, (rect.bottom - rect.top) / 4, 100, 30, NULL);
	SetWindowPos(buttonShow, NULL, (rect.right - rect.left) / 2 - 100, (rect.bottom - rect.top) / 4 , 100, 30, NULL);
	SetWindowPos(buttonScroll, NULL, (rect.right - rect.left) / 2 - 100, (rect.bottom - rect.top) / 4, 100, 30, NULL);
	SetWindowPos(buttonScale, NULL, (rect.right - rect.left) / 2 - 100, (rect.bottom - rect.top) / 4+60, 100, 30, NULL);
}

void drawText(HDC hDc)
{
	RECT rect = { 0 };
	GetWindowRect(hMainWnd, &rect);

	TCHAR out1[] = L"Данное приложение имеет основное и контекстное меню.";
	TCHAR out2[] = L"Есть 3 картинки на вывод заднего фона их можно выбрать";
	TCHAR out3[] = L"как в основном так и в контекстном меню. Так же есть";
	TCHAR out4[] = L" 2 режима отображения картинко.";
	TCHAR outAlt[] = L"";
	if (menuPage == 4)
	{
		TextOut(hDc, (rect.right - rect.left) / 2 - 53 / 2 * 8, (rect.bottom-rect.top)/4, out1, 53);
		TextOut(hDc, (rect.right - rect.left) / 2 - 55 / 2 * 8, (rect.bottom - rect.top) / 4+20, out2, 55);
		TextOut(hDc, (rect.right - rect.left) / 2 - 53 / 2 * 8, (rect.bottom - rect.top) / 4+40, out3, 53);
		TextOut(hDc, (rect.right - rect.left) / 2 - 32 / 2 * 8, (rect.bottom - rect.top) / 4+60, out4, 32);
	}
	else
	{
		TextOut(hDc, 330, 5, outAlt, 0);
	}

}

// Управляющая функция:
int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow) 
{

	HInst=hInst;
	TCHAR szClassName[] = L"Мой класс"; // строка с именем класса
	
	MSG msg; // создём экземпляр структуры MSG для обработки сообщений
	WNDCLASSEX wc; // создаём экземпляр, для обращения к членам класса WNDCLASSEX
	wc.cbSize = sizeof(wc); // размер структуры (в байтах)
	wc.style = CS_HREDRAW | CS_VREDRAW; // стиль класса окошка
	wc.lpfnWndProc = WndProc; // указатель на пользовательскую функцию
	wc.lpszMenuName = NULL; // указатель на имя меню (у нас его нет)
	wc.lpszClassName = szClassName; // указатель на имя класса
	wc.cbWndExtra = NULL; // число освобождаемых байтов в конце структуры
	wc.cbClsExtra = NULL; // число освобождаемых байтов при создании экземпляра приложения
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO); // декриптор пиктограммы
	wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO); // дескриптор маленькой пиктограммы (в трэе)
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); // дескриптор курсора
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // дескриптор кисти для закраски фона окна
	wc.hInstance = hInst; // указатель на строку, содержащую имя меню, применяемого для класса

	RegisterClassEx(&wc);

	hMainWnd = CreateWindow(szClassName, L"Полноценная оконная процедура", WS_OVERLAPPEDWINDOW, 0, 0, 600, 600,(HWND)NULL, NULL, HINSTANCE(hInst),  NULL);


	RECT rect = { 0 };
	GetWindowRect(hMainWnd, &rect);

	hGreenScroll = CreateWindow(L"scrollbar", NULL,
		WS_CHILD | WS_VISIBLE | SBS_HORZ, rect.left, rect.bottom - 74, rect.right - rect.left - 30, 15,
		hMainWnd, (HMENU)-1, HInst, NULL);


	vGreenScroll = CreateWindow(L"scrollbar", NULL,
		WS_CHILD | WS_VISIBLE | SBS_VERT, rect.right - 30, rect.top, 15, rect.bottom - rect.top - 74,
		hMainWnd, (HMENU)-1, HInst, NULL);


	ShowWindow(hMainWnd, nCmdShow);
	UpdateWindow(hMainWnd);
	

	

	

	//HWND hStatusWindow = CreateStatusWindow(WS_CHILD | WS_VISIBLE, L"", hMainWnd, 5000);
	

	HMENU hPopMenuFile = CreatePopupMenu();
	HMENU hPopMenuBackground = CreatePopupMenu();
	 hPopMenuShow = CreatePopupMenu();
	 hPopMenuImage = CreatePopupMenu();

	HMENU hmenu1 = CreateMenu();
	

	AppendMenu(hmenu1, MF_STRING | MF_POPUP, (UINT)hPopMenuFile, L"&File");
	AppendMenu(hmenu1, MF_STRING | MF_POPUP, (UINT)hPopMenuBackground, L"&Background");
	AppendMenu(hmenu1, MF_STRING | MF_POPUP, (UINT)hPopMenuImage, L"&Image");
	AppendMenu(hmenu1, MF_STRING, 1013, L"&About");

	AppendMenu(hPopMenuFile, MF_STRING, 1001, L"Exit");

	AppendMenu(hPopMenuBackground, MF_STRING | MF_POPUP, (UINT)hPopMenuShow, L"Show");
	AppendMenu(hPopMenuShow, MF_STRING | MF_CHECKED, 1002, L"Scroll");
	AppendMenu(hPopMenuShow, MF_STRING | MF_UNCHECKED, 1003, L"Scale");

	AppendMenu(hPopMenuImage, MF_STRING | MF_CHECKED, 1004, L"Image1");
	AppendMenu(hPopMenuImage, MF_STRING | MF_UNCHECKED, 1005, L"Image2");
	AppendMenu(hPopMenuImage, MF_STRING | MF_UNCHECKED, 1006, L"Image3");


	SetMenu(hMainWnd, hmenu1);
	SetMenu(hMainWnd, hPopMenuFile);
	SetMenu(hMainWnd, hPopMenuBackground);
	SetMenu(hMainWnd, hPopMenuShow);
	SetMenu(hMainWnd, hPopMenuImage);

	createButtons();


	while (GetMessage(&msg, NULL, NULL, NULL)) { // извлекаем сообщения из очереди, посылаемые фу-циями, ОС
		TranslateMessage(&msg); // интерпретируем сообщения
		DispatchMessage(&msg); // передаём сообщения обратно ОС
	}
	return msg.wParam; // возвращаем код выхода из приложения
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	HBITMAP bmPicture;
	PAINTSTRUCT ps;
	UINT uCheck0;
	UINT uCheck1;
	UINT uCheck2;
	HDC	hDc;
	
	switch (uMsg) 
	{

	case WM_HSCROLL:

		switch (LOWORD(wParam)) {		

			//сдвиг на линию вправо
		case SB_LINERIGHT:
			nxPos+=10;
			break;

		case SB_LINELEFT:
			nxPos-=10;
			break;

		case SB_THUMBTRACK:
			if (nxPos + 15 < HIWORD(wParam))
			{
				nxPos = HIWORD(wParam);
			}

			if (nxPos - 15 > HIWORD(wParam))
			{
				nxPos = HIWORD(wParam);
			}
			break;
			InvalidateRect(hWnd, NULL, TRUE);
		}

		//Передвинем движок на изменённую позицию
		SetScrollPos(hGreenScroll, SB_CTL, nxPos, TRUE);
		return 0;

	case WM_VSCROLL:

		switch (LOWORD(wParam)) {

			//сдвиг на линию вправо
		case SB_LINEDOWN:
			nyPos+=10;
			break;

		case SB_LINEUP:
			nyPos-=10;
			break;

		case SB_THUMBTRACK:
			if (nyPos + 15 < HIWORD(wParam))
			{
				nyPos = HIWORD(wParam);
			}

			if (nyPos - 15 > HIWORD(wParam))
			{
				nyPos = HIWORD(wParam);
			}
			
			break;

			InvalidateRect(hWnd, NULL, TRUE);
		}
		//Передвинем движок на изменённую позицию
		SetScrollPos(vGreenScroll, SB_CTL, nyPos, TRUE);
		return 0;

	case WM_PAINT:
		drawScrols();
		drawButtons();
		
		switch (image)
		{
		case 0:
			hDc = BeginPaint(hWnd, &ps);

			bmPicture = LoadBitmap(HInst, MAKEINTRESOURCE(IDB_BITMAP1));
			
			DrawBitmap(hDc, bmPicture, 0, 0);
			drawText(hDc);
			break;
		case 1:
			hDc = BeginPaint(hWnd, &ps);

			bmPicture = LoadBitmap(HInst, MAKEINTRESOURCE(IDB_BITMAP2));

			DrawBitmap(hDc, bmPicture, 0, 0);
			drawText(hDc);
			break;
		case 2:
			hDc = BeginPaint(hWnd, &ps);

			bmPicture = LoadBitmap(HInst, MAKEINTRESOURCE(IDB_BITMAP3));

			DrawBitmap(hDc, bmPicture, 0, 0);
			drawText(hDc);
			break;
		}
		return(0);
	case WM_DESTROY:
		PostQuitMessage(NULL); 
		return 0;
	case WM_COMMAND:
		switch (LOWORD(wParam)) 
		{
		case 1000:
			menuPage = 0;
			break;
		case 1001:
			PostQuitMessage(NULL);
			break;

		case 1002:
			mode = 0; 

			CheckMenuItem(hPopMenuShow, 1002, MF_CHECKED);
			CheckMenuItem(hPopMenuShow, 1003, MF_UNCHECKED);

			ShowWindow(vGreenScroll, SW_SHOW);
			ShowWindow(hGreenScroll, SW_SHOW);

			break;

		case 1003:
			mode = 1;

			CheckMenuItem(hPopMenuShow, 1002, MF_UNCHECKED);
			CheckMenuItem(hPopMenuShow, 1003, MF_CHECKED);

			ShowWindow(vGreenScroll, SW_HIDE);
			ShowWindow(hGreenScroll, SW_HIDE);

			
			break;

		case 1004:
		
			CheckMenuItem(hPopMenuImage, 1004, MF_CHECKED);
			CheckMenuItem(hPopMenuImage, 1005, MF_UNCHECKED);
			CheckMenuItem(hPopMenuImage, 1006, MF_UNCHECKED);
			image = 0;

			
			break;

		case 1005:
			
			CheckMenuItem(hPopMenuImage, 1004, MF_UNCHECKED);
			CheckMenuItem(hPopMenuImage, 1005, MF_CHECKED);
			CheckMenuItem(hPopMenuImage, 1006, MF_UNCHECKED);

			image = 1;
			
			break;

		case 1006:
		
			CheckMenuItem(hPopMenuImage, 1004, MF_UNCHECKED);
			CheckMenuItem(hPopMenuImage, 1005, MF_UNCHECKED);
			CheckMenuItem(hPopMenuImage, 1006, MF_CHECKED);

			image = 2;
			
			break;

		
		case 1010:
			menuPage = 1;
			
			break;

		case 1011:
			menuPage = 2;
			
			break;

		case 1111:
			menuPage = 5;

			break;

		case 1012:
			menuPage = 3;
			
			break;

		case 1013:
			menuPage = 4;
			
			break;
		}
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam); // если закрыли окошко
	}
	return NULL; // возвращаем значение
}


