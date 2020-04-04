#pragma once
#include"Color.h"
#include"DynamicArray.h"
#include"Move.h"


#include<iostream>
class IBoard;
class Figure
{	
protected:
	char* name;
	IBoard * board;
	Position* position;
	DynamicArray<Position*> rules;
	DynamicArray<Figure*>* takenFigures;
private:
	Color color;
	bool isTaken_m;
	int turnTaken;
public:
	Figure() = delete;
	Figure& operator =(Figure&) = delete;
	Figure(Figure&) = delete;
	Figure(Position* position, Color color, DynamicArray<Figure*>*);
	
	char*  getName() const;
	void  setName(const char* name);
	Color getColor()const;
	int getRow() const;
	int getColumn()const;
	void setRow(int row);
	void setColumn(int column);
	int getTurnTaken()const;
	void setTurnTaken(int turn);
	bool setBoard(IBoard * board);
	bool isTaken()const;
	void makeNonTaken();

	std::ostream& printStats(std::ostream& os);
	void getTakenFiguresList(DynamicArray<Figure*>* result);
	void pushTakenFigureList(Figure* figure);
	void deleteLastTakenFigure();
	Figure * getLastTakenFigure();
	virtual bool moveFigure(int row, int column);
	virtual void getPossibleMoves( DynamicArray<Move*>* result) ;
	virtual ~Figure();

};

