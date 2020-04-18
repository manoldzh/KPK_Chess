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
/*

bug list
pawn could not ataack -check possible moves generator - fixed
 bishop move in place where other figure was - check figure move set empty board tile - fixed (tight coupled figure and board lead to programmer msitakes)


  
  CAUTION - Figure knows it's corrdinates and board knows every figure coordinates
  // The reason for that's we identify uniquely each figure by it's coordinates- or it's taken 
  // lead to programmer forgetting to update figure coordinates
  // TODO : add auto update mechanism or store the information only in one  place, and add unique id to each figure 
*/

int main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

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

