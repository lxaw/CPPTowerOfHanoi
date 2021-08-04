#pragma once
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

