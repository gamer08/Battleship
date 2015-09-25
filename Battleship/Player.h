#ifndef _PLAYER_
#define _PLAYER_

#include "PlayerObserver.h"
#include "Board.h"
#include <vector>

class Ship; //déclaration avancée pour eviter une redondance cyclique;

class Player : PlayerObserver
{
private:
	Player(const Player&) = delete;
	Player& operator=(const Player& Player) = delete;

	Board* _board;
	PlayerObserver* _opponent;
	int _score;

public:
	Player();
	~Player();

	bool PlaceShip(const Position position, Ship* ship, int orientation);
	void PlaceShips(std::vector<Ship*> ships);

	void SetOpponent(PlayerObserver* opponent);
	void RemoveOpponent();

	void NotifyShot(const Position position);
	HitType OnNotify(const Position position);
};

#endif