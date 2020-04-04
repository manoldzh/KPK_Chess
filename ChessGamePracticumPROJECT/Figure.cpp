#include "stdafx.h"
#include "Figure.h"
#include"Position.h"
#include"IBoard.h"
#include<iostream>



#pragma warning(disable : 4996)



Figure::Figure(Position* position, Color color, DynamicArray<Figure*>*din){
	this->position = position;
	this->color = color;
	this->isTaken_m = false;
	this->takenFigures = din;
	this->turnTaken = -1;

}

char *  Figure::getName() const{
	char* result = new char[strlen(this->name) + 1];
	strcpy(result, this->name);
	return result;
}

void Figure::setName(const char * name){
	if (this->name != nullptr){
		delete this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Color Figure::getColor() const{
	return this->color;
}

int Figure::getRow() const{
	return this->position->getRow();
}

int Figure::getColumn() const{
	return this->position->getColumn();
}

void Figure::setRow(int row){
	if (this->isTaken_m == false){
		if (position->areValid(row, this->getColumn())){
			this->position->setRow(row);
		}
	}
}

void Figure::setColumn(int column){
	if (this->isTaken_m == false){
		if (position->areValid(this->getRow(), column))
		{
			this->position->setCol(col);
		}
	}
	else {
		// TODO throw exception
	}
}

int Figure::getTurnTaken() const{
	// if figure is not taken return -1
	return this->turnTaken;
}

void Figure::setTurnTaken(int turn){
	if (turn > 0){
		this->isTaken_m = true;
		this->turnTaken = turn;
	}
	else {
		// TODO throw exception
	}

}

bool Figure::setBoard(IBoard * board){
	if (board != nullptr){
		this->board = board;
		return true;
	}
	return false;

}

bool Figure::isTaken() const{
	return this->isTaken_m;
}

void Figure::makeNonTaken(){
	this->isTaken_m = false;
}

void Figure::getTakenFiguresList(DynamicArray<Figure*>* result){
	/// results of this function may be result call non constant members unsafe
	/// might lead to program crash 
	*result = *(this->takenFigures);
}

void Figure::pushTakenFigureList(Figure * figure){
	this->takenFigures->push_back(figure);
}

void Figure::deleteLastTakenFigure(){
	this->takenFigures->remove_by_index(takenFigures->get_size() - 1);
}

Figure* Figure::getLastTakenFigure(){
	return this->takenFigures->get_ElementAtIndex(takenFigures->get_size() - 1);
}

bool Figure::move(int row, int column){
	DynamicArray<Move*> moves;
	this->getPossibleMoves(&moves);
	for (unsigned int i = 0; i < moves.get_size(); i++){
		if (moves.get_ElementAtIndex(i)->getToRow() == row &&
			moves.get_ElementAtIndex(i)->getToColumn() == column){
			if ((board->isEmpty(row, column)) == true && (moves.get_ElementAtIndex(i)->getIsAttacking() == false)){
				return true;
			}
			else if (!(board->isEmpty(row, column)) && moves.get_ElementAtIndex(i)->getIsAttacking()) {
				return true;
			}
		}
	}
	return false;
}

std::ostream& Figure::printStats(std::ostream & os){
	Figure* element;
	os << "Figure" << " Color:" << this->getColor() << " Name:" << this->getName() << " Capture figures:" << std::endl;
	for (unsigned int i = 0; i < this->takenFigures->get_size(); i++){
		os << ". --------------------------" << std::endl;
		element = this->takenFigures->get_ElementAtIndex(i);
		os << i << std::endl
			<< "Name: " << element->getName() << std::endl
			<< "Color:" << element->getColor() << std::endl
			<< "Turn taken:" << element->getTurnTaken() << std::endl;

	}
	os << std::endl << "--------------------------" << std::endl;
	return os;
}

void Figure::getPossibleMoves(DynamicArray<Move*>* result){
	int row, column, tempRow, tempColumn;
	Color currentColor;
	row = position->getRow();
	column = position->getColumn();
	currentColor = board->getFigure(row, column)->getColor();


	if (!board->isEmpty(row, col)){
		for (unsigned int p = 0; p < rules.get_size(); p++){
			tempRow = row + rules.get_ElementAtIndex(p)->getRow();
			tempColumn = column + rules.get_ElementAtIndex(p)->getColumn();

			if (position->areValid(tempRow, tempColumn)){

				if (board->isEmpty(tempRow, tempColumn)){
					// if board is empty and attacking move is false
					result->push_back(new Move(row, col, tempRow, tempCol));
				}
				// if there is enemy figure and attacking move is true

				else if (board->getFigure(tempRow, tempColumn)->getColor() != currentColor){
					result->push_back(new Move(row, col, tempRow, tempColumn, true));
				}
			}
		}
	}
}


Figure::~Figure(){
	std::cout << "hit delete figure";
	delete position;
	delete[] name;
}


