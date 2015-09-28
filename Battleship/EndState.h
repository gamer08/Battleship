#ifndef _ENDSTATE_
#define _ENDSTATE_

#include "State.h"

class Player;

class EndState : public State
{
	public:
	EndState(BattleshipGame* battleship, Player* winner);
	~EndState();

	void Enter();
	void Execute();
	void Exit();
	bool IsRunning();

private:
	bool _isRunning;
	
	Player* _winner;

};

#endif