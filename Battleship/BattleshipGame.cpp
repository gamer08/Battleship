#include "BattleshipGame.h"
#include "Ship.h"

BattleshipGame::BattleshipGame() :_currentState(nullptr)
{

}

BattleshipGame::~BattleshipGame()
{
	delete _currentState;
	
	for (Player* player : _players)
		delete player;

	_players.clear();
}

void BattleshipGame::SetNewState(State* state)
{
	_currentState->Exit();
	delete _currentState;

	_currentState = state;
	_currentState->Enter();
}

void BattleshipGame::Start()
{
	_players.push_back(new Player());
	/*_players.push_back(new Player());*/

	_currentState = State::NewDefaultState(this);
	_currentState->Enter();
}

void BattleshipGame::Run()
{
	while (_currentState->IsRunning())
		_currentState->Execute();
}