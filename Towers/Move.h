// Written (with love) by Lex Whalen
#pragma once

/*
This class represents a single move.
A move would be in form (fromPegID, toPegID).
For instance, moving from left to middle: (0,1)
*/

class Move
{
public:
	Move() {
		_moveArr[0] = 0;
		_moveArr[1] = 0;
	}
	Move(int from, int to) {
		_moveArr[0] = from;
		_moveArr[1] = to;
	};

	int _moveArr[2];
};

