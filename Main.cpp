/*
Copiright 1999-2002,Sasha Paholkov 
email: Sasha4685847@mail.ru
*/
#define STRICT
#define WIN32_LEAN_AND_MEAN
#include "main.h"
#include <windowsx.h>
#include <math.h>
#include <mmsystem.h>

char szErrorMessage[255];	
//Обработчики сообщений Windows
BOOL DX_OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);
void DX_OnDestroy(HWND hwnd);
void DX_OnTimer(HWND hwnd, UINT id);
void DX_OnActivate(HWND hwnd, UINT state, HWND hwndActDeact, BOOL fMinimized);
void DX_OnKey(HWND hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags);
void DX_OnIdle(HWND hwnd);

DWORD dwGlobPrevTime;
DWORD dwGlobCurTime;

//Оконная процедура
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Характеристики таймера
#define TIMER_ID	1
unsigned int TimerId;
//Флаг активности нашего приложения
BOOL	bActive;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	WNDCLASSEX wndClass;
	HWND hWnd;
	MSG msg;

	//Регистрация оконного класса
	wndClass.cbSize       =sizeof(wndClass);
	wndClass.style        =CS_HREDRAW|CS_VREDRAW;
	wndClass.lpfnWndProc  =WndProc;
	wndClass.cbClsExtra   =0;
	wndClass.cbWndExtra   =0;
	wndClass.hInstance    =hInst;
	wndClass.hIcon        =LoadIcon(NULL,IDI_WINLOGO);
	wndClass.hCursor      =LoadCursor(NULL,IDC_ARROW);
	wndClass.hbrBackground=NULL;//Обратите внимание!!!
	wndClass.lpszMenuName =NULL;
	wndClass.lpszClassName=ClassName;
	wndClass.hIconSm      =LoadIcon(NULL,IDI_WINLOGO);
	RegisterClassEx(&wndClass);

	//Создание окна на основе класса
	hWnd=CreateWindowEx(
		0,//WS_EX_TOPMOST,//Дополнительный стиль окна
		ClassName,	//Класс окна
		AppName,	//Текст заголовка
		WS_POPUP|
		WS_MAXIMIZE,	//Стиль окна
		0,0,		//Координаты X и Y
		GetSystemMetrics(SM_CXSCREEN),
		GetSystemMetrics(SM_CYSCREEN),//Ширина и высота
		NULL,		//Дескриптор родительского окна
		NULL,		//Дескриптор меню
		hInst,		//Описатель экземпляра
		NULL);		//Дополнительные данные
	ShowCursor(FALSE);
	ShowWindow(hWnd,nCmdShow);
	UpdateWindow(hWnd);
	
	if (!InitDirectDraw(hWnd))
		return FALSE;
	if (!InitDirectInput(hWnd))
		return FALSE;
	if(DS)
	if (!InitDirectSound(hWnd))
	{		
		wsprintf(szErrorMessage, "Sound Disabled");
		ShowCursor(TRUE);
		MessageBox(hWnd, szErrorMessage, AppName, MB_OK);
		ShowCursor(FALSE);
		DS=0;
		SOUND=0;
		//
	}
	else
		SOUND=0;
#ifndef NOMUSIC
	if(DM)
		if (!InitDirectMusic(hWnd))
		{
			wsprintf(szErrorMessage, "Music Disabled");
			ShowCursor(TRUE);
			MessageBox(hWnd, szErrorMessage, AppName, MB_OK);
			ShowCursor(FALSE);
			DM=0;
			MUSIC=0;
			}
	//	else
	//	 MUSIC=0;
#endif
	if (!InitGame(hWnd))
		return FALSE;
	//Главный цикл программы
	while (TRUE)
	{
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
		{
			if (msg.message==WM_QUIT)
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
			if (bActive)//Только если приложение активно!
			{
				DX_OnIdle(hWnd);
			}
	}
	return (msg.wParam);
}
//---------------------------------------------------------
//	Оконная процедура
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
		HANDLE_MSG(hWnd,WM_CREATE,DX_OnCreate);
		HANDLE_MSG(hWnd,WM_DESTROY,DX_OnDestroy);
		HANDLE_MSG(hWnd,WM_TIMER,DX_OnTimer);
		HANDLE_MSG(hWnd,WM_ACTIVATE,DX_OnActivate);
		HANDLE_MSG(hWnd,WM_KEYDOWN,DX_OnKey);
		//HANDLE_MSG(hWnd,WM_SETCURSOR,Set_Cursor);
		   case WM_SETCURSOR:
            SetCursor(NULL);
			return (0);
			break;
		   case	WM_PALETTECHANGED:
			   	return (0);
			   break;
	default:
		return DefWindowProc(hWnd,msg,wParam,lParam);
	}
}
		/* Обработчики сообщений */
//---------------------------------------------------------

BOOL DX_OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct)
{
//Установка таймера
	if (!SetTimer(hwnd,TIMER_ID,TIMER_RATE,NULL))
		return (FALSE);
	return (TRUE);
}
//---------------------------------------------------------
void DX_OnDestroy(HWND hwnd)
{
	bActive=FALSE;
	KillTimer(hwnd,TIMER_ID);
	#ifndef NOMUSIC
	StopMidi();
	RemoveDirectMusic();
	#endif
	RemoveDirectSound();
	RemoveDirectInput();
	RemoveDirectDraw();
	ShowCursor(TRUE);
	PostQuitMessage(0);
}
//---------------------------------------------------------
void DX_OnTimer(HWND hwnd, UINT id)
{
	extern sec;
	if (bActive)
	//	NextTick();
	sec++;
}
//---------------------------------------------------------
void DX_OnIdle(HWND hwnd)
{
	extern Quit;//
	if(	Quit==1)
		DestroyWindow(hwnd);
	else
	{
	dwGlobCurTime=timeGetTime();
	if((dwGlobCurTime-dwGlobPrevTime)>=30)
		{			
		dwGlobPrevTime=dwGlobCurTime;
		NextTick();
		ProcessMouse();
		DrawFrame();
		}
	//ProcessMouse();
	//DrawFrame();
	
	}
}
//---------------------------------------------------------
void DX_OnKey(HWND hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags)
{
	int static temp=0;
	
	if (vk==VK_SPACE)
	{	NextTick();
		INVENTORY=0;
		QUEST=0;
		MAGIA=0;
		OPIT=0;
		MAP=0;

	}
	if (vk==VK_ESCAPE)		
		switch(mode)
		{
		case SPLASH:
			mode=BASE_MENU;
			break;
		case BASE_MENU:
			DestroyWindow(hwnd);
			break;
		case DEATH:
			MENU++;
			if(MENU>1)
				MENU=0;
			break;
		case 25:
			mode=S_OBJ;
			break;
		case 21:
			mode=S_OBJ;
			break;
		case 20:
			mode=S_OBJ;
			break;
		case S_OBJ:
			mode=0;
			break;
		case PEOPLE:
			mode=0;
			break;
		case D_OBJ:
			mode=0;
			break;
		case 0:
			//MENU++;
			//if(MENU>1)
			//	MENU=0;
			MENU=MENU^1;
			if(MENU>1)
				MENU=0;
			if(OPTIONS==1)
				{
				OPTIONS=0;
				MENU=0;
				}
			break;
		}
	if (vk==VK_F1)
		nDEBUG=1;
	if (vk==VK_F2)
		nDEBUG=0;
	if (vk==VK_F3)
		mode=DEATH;
	if (vk==VK_F4)
		PANEL_UPDATE=1;
	if (vk==VK_F5)
		modeinfo++;
	if (vk==VK_F6)
		modeinfo--;
	if (vk==VK_F7)
		nUstalost+=5;	
	if (vk==VK_F8)
			nUstalost-=5;
	if (vk==VK_F9)
		if(nLife<65)nLife+=5;	
//	if (vk==VK_ADD)
//		level+=1;	
//	if (vk==VK_SUBTRACT)
//		level-=1	;
}
//---------------------------------------------------------
void DX_OnActivate(HWND hwnd, UINT state, HWND hwndActDeact, BOOL fMinimized)
{
	//Обновить флаг состояния активности
	if (state==WA_INACTIVE)
		bActive=FALSE;
	else
		bActive=TRUE;
}
