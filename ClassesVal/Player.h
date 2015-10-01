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
	std::string _name;

public:
	Player(std::string name);
	~Player();

	bool PlaceShip(const Position position, Ship* ship, int orientation);
	void PlaceShips(std::vector<Ship*> ships);
	void DrawBoard();

	void SetOpponent(PlayerObserver* opponent);
	void RemoveOpponent();

	void NotifyShot(const Position position);
	HitType OnNotify(const Position position); 
	void setName(std::string name) { _name = name; };
	std::string getName() { return _name; };
};

#endif