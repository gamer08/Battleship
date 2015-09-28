#ifndef _PLAYSTATE_
#define _PLAYSTATE_

#include "State.h"
#include <vector>
#include "Player.h"

class PlayState : public State
{
	public:
	PlayState(BattleshipGame* battleship);
	~PlayState();

	void Enter();
	void Execute();
	void Exit();
	bool IsRunning();

private:
	bool _isRunning;

	std::vector<Player*> _players;

};

#endif