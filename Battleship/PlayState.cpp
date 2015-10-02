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
	
	// Tests de range et de déplacement

	////_players[0]->Attack();
	//_players[0]->DrawBoard();
	//system("pause");
	//system("cls");
	//_players[0]->MoveShip();
	//system("cls");
	///*_players[0]->DrawBoard();
	//system("pause");*/
	
}

void PlayState::Exit()
{

}

bool PlayState::IsRunning()
{
	return _isRunning;
}