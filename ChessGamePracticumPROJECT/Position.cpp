#include "stdafx.h"
#include "Position.h"
#include<assert.h>
#include"GlobalVariables.h"
#include<iostream>


int Position::getRow() const{
	return this->row;
}


int Position::getColumn() const{
	return this->col;
}

void Position::setRow(int row){
	this->row = Row;
}


void Position::setColumn(int column){
	this->column = column;
}


Position::Position(){
	setRow(0);
	setCol(0);
}


Position::Position(int row, int column){
	setCol(column);
	setRow(row);
}


bool Position::areValid(int row, int column){
	if (row < 0 || row >= GlobalVaribles::SIZE || col < 0 || column >= GlobalVaribles::SIZE) {
		return false;
	}
	return true;
}

bool Position::areValid(const Position* position){
	if (position->row < 0 || position->row>GlobalVaribles::SIZE || position->column <0 || position->col > GlobalVaribles::SIZE) {
		return false;
	}
	return true;
}


Position::~Position(){}
