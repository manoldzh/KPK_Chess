#include "stdafx.h"
#include "Square.h"

bool Square::isEmpty() const {
	return this->_isEmpty;
}

void Square::setFigure(Figure* figure){
	this->figure = figure;
	this->_isEmpty = false;
}

Figure * Square::getFigure() const {
	return this->figure;
}

Figure * Square::removeFigure(){
	this->_isEmpty = true;
	Figure* result = this->figure;
	this->figure = nullptr;
	return result;
}

Square::Square(){
	this->_isEmpty = true;
}


Square::~Square(){
	 std::cout << "delete square";
}
