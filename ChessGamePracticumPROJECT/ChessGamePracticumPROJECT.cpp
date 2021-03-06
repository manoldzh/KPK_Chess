// ChessGamePracticumPROJECT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdafx.h"
#include"Board.h"
#include"ConsoleView.h"
#include<iostream>
#include<Windows.h>
#include"GlobalVariables.h"
#include"DynamicArray.h"
#include "IGame.h"
#include"Game.h"
#pragma warning(disable: 4996) 
using namespace std;
const int WindowWidth = 1400;
const int WindowHeight = 1200;
const int XFontSize = 9;
const int YFontSize = 9;

int main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); 

	MoveWindow(console, r.left, r.top, WindowWidth, WindowHeight, TRUE); 


	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.dwFontSize.X = XFontSize;
	cfi.dwFontSize.Y = YFontSize;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	std::ostream& s = std::cout;
	ConsoleView* view = new ConsoleView(s);

	IGame* game = new Game(view);
	game->startGame();
	
	return 0;
}

