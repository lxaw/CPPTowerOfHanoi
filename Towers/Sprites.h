#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"

#include "Stack.h"

class Block
{
public:
	unsigned int _width;
	unsigned int _height;
	unsigned int _x;
	unsigned int _y;

	// sfml stuff
	sf::RectangleShape _rect;
	sf::Color _color;

	// for positioning
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
	Disk(int diskID,sf::Color color,unsigned int pegX,int level,int max_level,unsigned int win_w,unsigned int win_h);

	void changePos(unsigned int pegX, int level);

	bool operator < (Disk const& aDisk);
	bool operator > (Disk const& aDisk);

	unsigned int _win_w = 0;
	unsigned int _win_h = 0;
	int _max_level = -1;

	unsigned int _x = 0;
	unsigned int _y = 0;

	int _diskID = -1;

	sf::Color _color = sf::Color::Black;

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
};

