#include "Ship.h"

Ship::Ship(int length, int fireRange) : _length(length), _fireRange(fireRange)
{
	_position = new Position();
}

Ship::~Ship()
{
	delete _position;
}

bool Ship::CanShotAtPosition(Position position)
{
	return true;
}