#include "PlayState.h"
#include "BattleshipGame.h"

PlayState::PlayState(BattleshipGame* battleship) :State(battleship)
{

}

PlayState::~PlayState()
{

}

void PlayState::Enter()
{
	_isRunning = true;
	_players = _battleship->GetPlayers();
}

void PlayState::Execute()
{
	system("cls");
	_players[0]->DrawBoard();
}

void PlayState::Exit()
{

}

bool PlayState::IsRunning()
{
	return _isRunning;
}