#pragma once
class Position
{
	int row, column;
public:
	int getRow()const;
	int getColumn()const;
	void setRow(int row);
	void setColumn(int column);
	Position();
	Position(int row, int column);
	static bool areValid(int row, int column);
	bool areValid(const Position * position);
	 ~Position();
};

