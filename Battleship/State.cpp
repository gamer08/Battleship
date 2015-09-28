#include "State.h"
#include "StartState.h"
#include "BattleshipGame.h"

State::State(BattleshipGame* battleship) : _battleship(battleship)
{

}

State::~State()
{

}

State* State::NewDefaultState(BattleshipGame* battleship)
{
	return new StartState(battleship);
}

void State::SetNewState(State* state)
{
	_battleship->SetNewState(state);
}

