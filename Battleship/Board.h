#ifndef _BOARD_
#define _BOARD_

#include "Ship.h"

class Board
{

private:

	struct Cell
	{
		char _displayCharacter;
		Ship* _ship;
		Cell()
		{
			_displayCharacter = '_';
			_ship = nullptr;
		}
		
		~Cell()
		{
			if (_ship) // test pour voir s'il pointe sur quelque chose;
				delete _ship;
		}
	};
	
	int _order;
	Cell** _grid;

	Board(){};
	Board(const Board&) = delete;
	Board& operator=(const Board& position) = delete;

	

public:

	Board(int order); // order c'est lordre de la matrice donc 1 = 1x1, 2 = 2x2
	~Board();
};

#endif 