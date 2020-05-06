#include "stdafx.h"
#include "Queen.h"
#include"Bishop.h"
#include"Rook.h"
#include"Figure.h"

/**
* Construct new Queen
*@param Position * position
*@param Color color
*@param DynamicArray<Figure * > * takenFigures
*@return Queen
*/
Queen::Queen(Position * position, Color color, DynamicArray<Figure*>* takenFigures) :Figure(position, color, takenFigures),Rook(position, color, takenFigures),Bishop(position, color, takenFigures){
	
	this->setName("Queen");
}

void Queen::getPossibleMoves(DynamicArray<Move*>* result){
	 Rook::getPossibleMoves(result);
}

Queen::~Queen(){
}
