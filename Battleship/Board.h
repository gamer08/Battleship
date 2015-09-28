#ifndef _BOARD_
#define _BOARD_

#include "Ship.h"
#include <vector>

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
			delete _ship;
		}
	};
	
	int _order;
	Cell** _grid;
	
	// Je ne suis pas encore décidé si je vais l'utiliser
	//std::vector<Ship*> _ships;

	Board(){};
	Board(const Board&) = delete;
	
	Board& operator=(const Board& position) = delete;
	
	bool PlaceShipIfEnoughSpace(const Position position, Ship* ship, int orientation);
	void AddShip(Ship* ship);

public:

	Board(int order); // order c'est lordre de la matrice donc 1 = 1x1, 2 = 2x2
	~Board();
	void DrawGrid();
	bool PlaceShipIfPossible(const Position position, Ship* ship, int orientation);
	Position ParsePositionFromInput(std::string input);
};

#endif 