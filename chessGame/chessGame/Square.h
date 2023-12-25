#pragma once

#include <iostream>
#include "PieceException.h"

constexpr int BOARD_SIZE = 8;

class Square
{
public:
	//constructors
	/**
	* constructor for Square.
	* @param x,y coordinates of the Square.
	*/
	Square();
	Square(const int x, const int y);

	//destructor
	/**
	* destructor for Square. frees memory allocated for Square.
	*/
	~Square();

	/*
	* getter of param x
	*/
	int getX() const;

	/*
	* getter of param y
	*/
	int getY() const;

	//operators
	/**
	* assignment operator for Square.
	* @param other Square to assignment to this Square.
	* @returns reference to the Square after assignment other Square.
	*/
	Square& operator=(const Square& other);
	/**
	* addition operator for Square.
	* @param other Square to add to this Square.
	* @returns reference to the Square after adding other Square.
	*/
	Square operator+(const Square& other) const;
	/**
	* addition assignment operator for Square.
	* @param other Square to add and assign to this Square.
	* @returns reference to the Square after adding and assigning other Square.
	*/
	Square& operator+=(const Square& other);
	/**
	* subtraction operator for Square.
	* @param other Square to subtract to this Square.
	* @returns reference to the Square after subtracting other Square.
	*/
	Square operator-(const Square& other) const;
	/**
	* subtraction assignment operator for Square.
	* @param other Square to subtract and assign to this Square.
	* @returns reference to the Square after subtracting and assigning other Square.
	*/
	Square& operator-=(const Square& other);
	/**
	* comparison operator for Square.
	* @param other Square to compare to this Square.
	* @returns true\false Square are equals.
	*/
	bool operator==(const Square& other) const;

private:
	int _x;
	int _y;
};
