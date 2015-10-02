#ifndef _SHIP_
#define _SHIP_

#include "Position.h"

class Ship
{
private:
	
	// rend inaccessible le constructeur par defaut, par copie et l'operateur d'assignation.	
	Ship(){};
	Ship(const Ship&) = delete;
	Ship& operator=(const Ship& ship) = delete;

	Position* _position;
	int _length;
	int _fireRange;
	bool _isSink;
	int _orientation;

public:

	Ship(int length, int fireRange);
	~Ship();

	void SetPosition(Position newPosition)
	{
		_position->_x = newPosition._x;
		_position->_y = newPosition._y;
	}

	Position GetPosition() const
	{
		return *_position;
	}

	void SetOrientation(int orientation)
	{
		_orientation = orientation;
	}

	int GetOrientation() const
	{
		return _orientation;
	}

	int GetLength() const
	{
		return _length;
	}

	bool IsSink() const
	{
		return _isSink;
	}
	
	bool CanAttackAtPosition(Position position);
	void MoveAtPosition(Position newPosition);

};

#endif