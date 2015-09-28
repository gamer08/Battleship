#ifndef _STATE_
#define _STATE_

class BattleshipGame;

class State
{

protected:
	BattleshipGame* _battleship;

	State(BattleshipGame* battleship);
	State(const State&);
	State& operator=(const State& State);
	void SetNewState( State* newState );

public:
	virtual ~State();

	static State* NewDefaultState(BattleshipGame* batteship);

	virtual void Enter() = 0;
	virtual void Execute() = 0;
	virtual void Exit() = 0;
	virtual bool IsRunning() = 0;

};

#endif