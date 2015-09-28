#include "EndState.h"
#include "BattleshipGame.h"
#include "Player.h"

EndState::EndState(BattleshipGame* battleship,  Player* winner ) :_winner(winner),State(battleship) 
{
}

EndState::~EndState()
{

}

void EndState::Enter()
{
	_isRunning = true;
}

void EndState::Execute()
{
	
}

void EndState::Exit()
{

}

bool EndState::IsRunning()
{
	return _isRunning;
}