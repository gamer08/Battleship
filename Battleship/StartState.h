#ifndef _STARTSTATE_
#define _STARTSTATE_

#include "State.h"

class StartState : public State
{
public:
	StartState(BattleshipGame* battleship);
	~StartState();

	void Enter();
	void Execute();
	void Exit();
	bool IsRunning();

private:
	bool _isRunning;
};

#endif