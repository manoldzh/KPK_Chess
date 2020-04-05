#include "stdafx.h"
#include "Horse.h"
#include"IBoard.h"

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



Horse::~Horse(){
}
