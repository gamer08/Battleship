#include "StartState.h"
#include "PlayState.h"
#include "Player.h"
#include "Ship.h"
#include "BattleshipGame.h"
#include <vector>

StartState::StartState(BattleshipGame* battleship) :State(battleship)
{

}

StartState::~StartState()
{

}

void StartState::Enter()
{
	_isRunning = true;
}

void StartState::Execute()
{
	std::vector<Player*> players = _battleship->GetPlayers();

	for (Player* player : players)
	{
		std::vector<Ship*> ships;

		ships.push_back(new Ship(1, 1));
		/*ships.push_back(new Ship(2, 2));
		ships.push_back(new Ship(3, 3));
		ships.push_back(new Ship(4, 4));
		ships.push_back(new Ship(5, 5));*/

		player->PlaceShips(ships);
		ships.clear();
	}

	SetNewState(new PlayState(_battleship));
}

void StartState::Exit()
{

}

bool StartState::IsRunning()
{
	return _isRunning;
}