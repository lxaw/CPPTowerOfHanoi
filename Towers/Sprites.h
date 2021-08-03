#pragma once

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
	Disk(int diskID,sf::Color color,unsigned int pegX,int level,int max_level,unsigned int win_w,unsigned int win_h);

	void changePos(unsigned int pegX, int level);

	unsigned int _win_w;
	unsigned int _win_h;
	int _max_level;

	unsigned int _x;
	unsigned int _y;

	int _diskID;

	sf::Color _color;
	
};

