#include "stdafx.h"
#include "ConsoleView.h"
#include"Color.h"
#include"GlobalVariables.h"
#include<assert.h>
#include<Windows.h>

void ConsoleView::printRowKing(int n, Color color)
{
	if (color == BLACK) {
		SetConsoleTextAttribute(this->hConsole, 12);
	}
	*output << king[n];
	SetConsoleTextAttribute(this->hConsole, 15);
}

void ConsoleView::printRowQueen(int n, Color color)
{
	if (color == BLACK) {
		SetConsoleTextAttribute(this->hConsole, 12);
	}
	*output << queen[n];
	SetConsoleTextAttribute(this->hConsole, 15);
}

void ConsoleView::printRowBishop(int n, Color color)
{
	if (color == BLACK) {
		SetConsoleTextAttribute(this->hConsole, 12);
	}
	*output << bishop[n];
	SetConsoleTextAttribute(this->hConsole, 15);
}

void ConsoleView::printRowHorse(int n, Color color)
{
	if (color == BLACK) {
		SetConsoleTextAttribute(this->hConsole, 12);
	}
	*output << horse[n];
	SetConsoleTextAttribute(this->hConsole, 15);
}

void ConsoleView::printRowRook(int n, Color color)
{
	if (color == BLACK) {
		SetConsoleTextAttribute(this->hConsole, 12);
	}
	*output << rook[n];
	SetConsoleTextAttribute(this->hConsole, 15);
}

void ConsoleView::printRowPawn(int n, Color color)
{
	if (color == BLACK) {
		SetConsoleTextAttribute(this->hConsole, 12);
	}
	*output << pawn[n];
	SetConsoleTextAttribute(this->hConsole, 15);
}

void ConsoleView::printBoard(IBoard * board)
{
	char* figName;
	Color figColor;
	for (int row = 0; row < GlobalVaribles::SIZE; row++)
	{
		*output << row;
		for (int printRow = 0; printRow < 10; printRow++)
		{


			for (int col = 0; col < GlobalVaribles::SIZE; col++)
			{
				if (printRow == 0) {
					*output << col << ' ' << ' ';
				}
				else {
					*output << ' ' << ' ';
				}

				if (!board->isEmpty(row, col)) {
					// the board position is non empty
					figName = board->getFigure(row, col)->getName();
					figColor = board->getFigure(row, col)->getColor();
					if (!strcmp(figName, "Pawn")) { printRowPawn(printRow, figColor); }
					else if (!strcmp(figName, "Rook")) { printRowRook(printRow, figColor); }
					else if (!strcmp(figName, "Bishop")) { printRowBishop(printRow, figColor); }
					else if (!strcmp(figName, "Horse")) { printRowHorse(printRow, figColor); }
					else if (!strcmp(figName, "Queen")) { printRowQueen(printRow, figColor); }
					else if (!strcmp(figName, "King")) { printRowKing(printRow, figColor); }
					else {
						assert(false);
					}
				}
				else {
					if (printRow == 0) {
						*output << "          ";
					}

					else {
						*output << "           ";
					}

				}
				*output << "|";
			}

			*output << std::endl;
			*output << " ";
		}

		for (int k = 0; k < GlobalVaribles::SIZE; k++) {
			*output << "_____________.";
		}
		*output << std::endl;
	}
}

void ConsoleView::printMessageNL(const char * message)
{
	*s << message << std::endl;
}

void ConsoleView::readCommand(char * command)
{
	std::cin.getline(command, 14, '\n');
}

std::ostream & ConsoleView::getStream()
{
	return *s;
}

ConsoleView::ConsoleView(std::ostream& s)
{
	this->s = &s;

	this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

ConsoleView::~ConsoleView()
{
}
