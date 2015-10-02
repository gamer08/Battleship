#include "Ship.h"
#include <math.h>

Ship::Ship(int length, int fireRange) : _length(length), _fireRange(fireRange)
{
	_position = new Position();
}

Ship::~Ship()
{
	delete _position;
}

bool Ship::CanAttackAtPosition(Position position)
{
	bool canReach = false;
	float demiLength, posX, posY, cX, cY, firstPart, secondPart;
	
	posX = position._x + 0.5f;
	posY = position._y + 0.5f;

	switch (_orientation)
	{

	case 0:
		demiLength = _length / 2.0f;
		cX = _position->_x + 0.5f;
		cY = _position->_y + demiLength;

		firstPart = powf(posX - cX, 2.0f) / powf(demiLength + _fireRange, 2.0f);
		secondPart = powf(posY - cY, 2.0f) / powf(0.5f + _fireRange, 2.0f);

		if (firstPart + secondPart <= 1)
			canReach = true;

		break;

	case 1:
		demiLength = _length / 2.0f;
		cX = _position->_x + demiLength;
		cY = _position->_y + 0.5f;

		firstPart = powf(posX - cX, 2.0f) / powf(0.5f + _fireRange, 2.0f);
		secondPart = powf(posY - cY, 2.0f) / powf(demiLength + _fireRange, 2.0f);

		if (firstPart + secondPart <= 1)
			canReach = true;

		break;

	default:
		break;
	}

	return canReach;
}