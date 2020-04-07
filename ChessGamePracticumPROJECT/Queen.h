#pragma once
#include "Figure.h"
#include"Bishop.h"
#include"Rook.h"
class Queen :
	public Rook, public Bishop
{	
public:
	Queen() = delete;
	Queen& operator =(Queen&) = delete;
	Queen(Queen&) = delete;

	Queen(Position* position, Color color, DynamicArray<Figure*>* takenFigures);
	void getPossibleMoves( DynamicArray<Move*>* result)  override;
	virtual ~Queen();
};

