#pragma once
#include"Position.h"
class Move
{
	Position* from;
	Position* to;
	bool isAttacking;
public:
	int getFromRow()const;
	int getToRow()const;
	int getFromColumn()const;
	int getToColumn()const;
	bool getIsAttacking()const;

	void setFromRow(int row);
	void setToRow(int row);
	void setFromColumn(int column);
	void setToColumn(int column);
	void setIsAttacking(bool isAttacking);

	void logToConsole();

	Move();
	Move(int rowFrom, int columnFrom, int rowTo, int columnTo, bool isAttacking = false);
	 ~Move();
};

