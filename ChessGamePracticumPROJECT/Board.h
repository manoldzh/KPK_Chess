#pragma once

#include"Square.h"
#include"GlobalVariables.h"
#include"IBoard.h"
#include"Figure.h"

class Board : public IBoard
{
	Square** board;
	DynamicArray< DynamicArray<Figure*> *> * arraysToDelete;
	DynamicArray<Figure*>*  figuresToDelete;
public:
	void placeFigures() override;
	bool isEmpty(int row, int column)	override;
	Figure* getFigure(int row, int column)	override;
	bool setFigure(int row, int column, Figure*)	override;
	bool makeTileEmpty(int row, int column) override;
	Board();
	~Board();
};

