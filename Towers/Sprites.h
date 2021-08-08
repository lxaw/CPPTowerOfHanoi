// Written (with love) by Lex Whalen
#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>

#include "Stack.h"

class Block
{
public:
	unsigned int _width = 0;
	unsigned int _height = 0;
	unsigned int _x = 0;
	unsigned int _y = 0;

	// sfml stuff
	sf::RectangleShape _rect;
	sf::Color _color;
};

class Peg: public Block
{
public:
	Peg();
	Peg(unsigned int peg_number, unsigned int win_w, unsigned int win_h);

	int _peg_number;
	unsigned int _margin;

};

class Disk :public Block 
{
public:
	Disk() = default;
	Disk(int diskID,sf::Color color,Peg peg,int level,unsigned int win_w,unsigned int win_h);

	// level keeps track of the height of disk
	int _level = 0;

	Peg peg;

	// adjusts the position of a disk on a peg
	void changePos(Peg newPeg, int level);

	bool operator < (Disk const& aDisk);
	bool operator > (Disk const& aDisk);

	unsigned int _win_w = 0;
	unsigned int _win_h = 0;

	unsigned int _x = 0;
	unsigned int _y = 0;

	int _diskID = -1;
	
	sf::Color _color = sf::Color::Black;

	// for printing out the disks
	inline
		friend std::ostream& operator << (std::ostream& os, Disk& aDisk) {
		os << aDisk._diskID;
		return os;
	}
};

class Background :public Block
{
public:
	Background(unsigned int win_w, unsigned int win_h);
	sf::Font _font;
	sf::Text _text;
};

