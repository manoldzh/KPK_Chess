#include "stdafx.h"
#include "Horse.h"
#include"IBoard.h"
/**
* Construct new Horse
*@param Position * position
*@param Color color
*@param DynamicArray<Figure * > * takenFigures
*@return Horse
*/
Horse::Horse(Position * position, Color color, DynamicArray<Figure*>* takenFigures) :Figure(position, color, takenFigures){
	this->setName("Horse");
	// 2 left up 1
	this->rules.push_back(new Position(-1, -2));
	// 2 left down 1
	this->rules.push_back(new Position(1, -2));
	// 2 right up 1
	this->rules.push_back(new Position(-1, 2));
	// 2 right down 1
	this->rules.push_back(new Position(1, 2));
	// 2 up left 1
	this->rules.push_back(new Position(-2, -1));
	// 2 up right 1
	this->rules.push_back(new Position(-2, 1));
	// 2 down left 1
	this->rules.push_back(new Position(2, -1));
	// 2 down right 1
	this->rules.push_back(new Position(2, 1));
}
/**
*Bishop Destructor
*/
Horse::~Horse(){
}
