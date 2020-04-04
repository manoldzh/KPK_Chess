#include "stdafx.h"
#include "Move.h"
#include"Position.h"
#include<iostream>

Move::Move(){
	this->to = new Position(0, 0);
	this->from = new Position(0, 0);
}

Move::Move(int rowFrom, int columnFrom, int rowTo, int columnTo, bool isAttacking){
	this->to = new Position(0, 0);
	this->from = new Position(0, 0);
	
	setToRow(rowTo);
	setToColumn(columnTo);
	setFromColumn(columnFrom);
	setFromRow(rowFrom);
	
	this->isAttacking = isAttacking;
}

int Move::getFromRow()const{
	return from->getRow();
}

int Move::getToRow()const{
	return to->getRow();
}

int Move::getFromColumn()const{
	return from->getColumn();
}

int Move::getToColumn()const{
	return to->getColumn();
}

bool Move::getIsAttacking() const{
	return this->isAttacking;
}

void Move::setFromRow(int row){
	from->setRow(row);
}

void Move::setToRow(int row){
	to->setRow(row);
}

void Move::setFromColumn(int column){
	from->setCol(column);
}

void Move::setToColumn(int column){
	to->setCol(column);
}

void Move::setIsAttacking(bool isAttacking){
	this->isAttacking = isAttacking;
}

void Move::logToConsole() {
	std::cout << " from row:" << getFromRow() << std::endl;
	std::cout << " from column:" << getFromColumn() << std::endl;

	std::cout << " to row:" << getToRow() << std::endl;
	std::cout << " to column:" << getToColumn() << std::endl;
	std::cout << "is Attacking move:" << getIsAttacking() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}
Move::~Move(){
	delete to;
	delete from;
}