#pragma once

#include <iostream>
#include "GameException.h"

constexpr int BOARD_SIZE = 8;

constexpr int SQUARE_STRING_LENGTH = 2;

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
	Square(const Square& other);

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

	void setSquare(const int x, const int y);

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

	/*
	* increase x by 1.
	* @returns true\false increasing worked.
	*/
	bool IncX();
	/*
	* increase y by 1.
	* @returns true\false increasing worked.
	*/
	bool IncY();
	/*
	* decrease x by 1.
	* @returns true\false increasing worked.
	*/
	bool DecX();
	/*
	* decrease y by 1.
	* @returns true\false increasing worked.
	*/
	bool DecY();

	/*
	* check if square is valid in a chess board
	* 
	* @param x - x value of board
	* @param y - y value of board
	* @return true if valid. false if not
	*/
	static bool checkSquare(const int x, const int y);

	/*
	* turn a sring in the length of 2 into square
	* @param move - string at size two reprecenting the square.
	* @param squ - square set to square in string.
	* @return true if square was valid. false if not.
	*/
	static bool getSqu(std::string& move, Square& squ);

private:
	int _x;
	int _y;
};
