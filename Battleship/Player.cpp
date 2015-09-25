#include "Player.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

Player::Player()
{
	_score = 0;
	_board = new Board(10);
}

Player::~Player()
{
	delete _board;
}

void Player::PlaceShips(std::vector<Ship*> ships)
{
	int nb = ships.size();
	
	
	std::string input;
	bool shipPlaced = false;
	for (int index = 0; index < nb; index++)
	{	
		while (!shipPlaced)
		{
			std::cout << "Enter position and orientation for ship " << (index + 1) << " in the for of A2 0" << "\n";
			std::getline(std::cin, input);

			std::istringstream inputStream(input);
			
			std::string positionInput;
			inputStream >> positionInput;

			std::string orientationInput;
			inputStream >> orientationInput;

			int orientation = atoi((orientationInput).c_str());

			Position position = _board->ParsePositionFromInput(positionInput);

			if (position._x != -1 && (position._y >= 0))
			shipPlaced =_board->PlaceShipIfPossible(position, ships[index], orientation);
		}

		system("cls");
		shipPlaced = false;
	}

	_board->DrawGrid();

	system("pause");
}

bool Player::PlaceShip(const Position position, Ship* ship, int orientation)
{
	return _board->PlaceShipIfPossible(position, ship, orientation);
}