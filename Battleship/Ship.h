#ifndef _SHIP_
#define _SHIP_

#include "Position.h"

class Ship
{
private:
	
	// rend inaccessible le constructeur par defaut, par copie et l'operateur d'assignation.
	
	Ship(){};
	Ship(const Ship&) = delete;
	Ship& operator=(const Ship& position) = delete;

	Position* _position;
	int _length;
	int _fireRange;

public:

	Ship(int length, int fireRange);
	~Ship();

	void SetPosition(Position newPosition)
	{
		_position->_x = newPosition._x;
		_position->_y = newPosition._y;
	}

	bool CanShotAtPosition(Position position);
};

#endif