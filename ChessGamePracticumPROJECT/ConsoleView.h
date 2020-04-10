#pragma once
#include "View.h"
#include<Windows.h>
const int rowsFigure = 10;
const int columsFigure = 12;
class ConsoleView :
	public View
{
public:
	std::ostream* s;
	HANDLE hConsole;
	char king[rowsFigure][columsFigure] = {
		"  =||=    ",
		" ++++++++  ",
		"========== ",
		" \\      /  ",
		"  |    |   ",
		"  |    |   ",
		"  |    |   ",
		"  |    |   ",
		" /      \\  ",
		"|________| ",
	};
	char queen[rowsFigure][columsFigure] = {
		"          ",
		"|\\ ,'`. /| ",
		"| ------ | ",
		" \\      /  ",
		"  |    |   ",
		"  |    |   ",
		"  |    |   ",
		"  |    |   ",
		" /      \\  ",
		"|________| ",
	};
	char bishop[rowsFigure][columsFigure] = {
		"          ",
		"     o     ",
		"   /\\^/\\   ",
		"  |  /  )  ",
		"  | /  /   ",
		"   Y  /    ",
		"   |  |    ",
		"   |  |    ",
		"  /    \\   ",
		" |______|  ",
	};
	char horse[rowsFigure][columsFigure] = {
		"          ",
		"           ",
		"  |\\__     ",
		" /   o\\__  ",
		"|    ___=\' ",
		"|    \\     ",
		" \\    \\    ",
		"  >    \\   ",
		" /      \\  ",
		"|________| ",
	};;
	char rook[rowsFigure][columsFigure] = {
		"          ",
		"           ",
		" _   _   _ ",
		"| |_| |_|| ",
		" \\      /  ",
		"  |    |   ",
		"  |    |   ",
		"  |    |   ",
		" /      \\  ",
		"|________| ",
	};
	char pawn[rowsFigure][columsFigure] = {
		"          ",
		"           ",
		"    __     ",
		"   (  )    ",
		"    ><     ",
		"   |  |    ",
		"  |    |   ",
		"  |    |   ",
		" /      \\  ",
		"|________| ",
	};
public:
	void printRowQueen(int n, Color color);
	void printRowBishop(int n, Color color);
	void printRowHorse(int n, Color color);
	void printRowRook(int n, Color color);
	void printRowPawn(int n, Color color);

public:
	ConsoleView() = delete;
	ConsoleView& operator =(ConsoleView&) = delete;
	ConsoleView(ConsoleView&) = delete;
	
	void printRowKing(int n, Color color);
	void printBoard(IBoard* board) override;
	void printMessageNL(const char*) override;
	void readCommand(char* command)override;
	std::ostream& getStream() override;

	ConsoleView(std::ostream& s);
	
	virtual ~ConsoleView();
};

