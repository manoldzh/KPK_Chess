#pragma once
#include "Figure.h"
/**
 * The <code>Horse</code> class represents Horse figure in a Chess game.
 */
class Horse :
	public Figure
{
public:
	Horse() = delete;
	Horse& operator =(Horse&) = delete;
	Horse(Horse&) = delete;
	Horse(Position* position, Color color, DynamicArray<Figure*>* takenFigures);
	
	virtual ~Horse();
};

