#ifndef _BATTLESHIPGAME_
#define _BATTLESHIPGAME_

#include "State.h"
#include <vector>
#include <memory>
#include "Player.h"

class BattleshipGame
{
private:

	friend class State;

	State* _currentState;
	std::vector<Player*> _players;
	
public:
	
	BattleshipGame();
	~BattleshipGame();
	
	void SetNewState(State* newState);
	void Start(/*std::weak_ptr<BattleshipGame> game*/);
	void Run();

	std::vector<Player*> GetPlayers() const
	{
		return _players;
	}
	

};

#endif