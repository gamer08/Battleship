#ifndef _PLAYER_
#define _PLAYER_

#include "Board.h"
#include <vector>

class Ship; //déclaration avancée pour eviter une redondance cyclique;

class Player
{
private:
	Player(const Player&) = delete;
	Player& operator=(const Player& Player) = delete;

	Board* _board;
	int _score;

public:
	Player();
	~Player();

	bool PlaceShip(const Position position, Ship* ship, int orientation);
	void PlaceShips(std::vector<Ship*> ships);
};

#endif