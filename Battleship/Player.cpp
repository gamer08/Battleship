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
	
	if (_opponent)
	_opponent->RemoveOpponent();
	
	delete _opponent;
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
			std::cout << "Enter position and orientation for ship " << (index + 1) << " in the form of A2 0" << "\n";
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
}

void Player::Attack()
{
	std::string input;
	Position attackPosition = Position(0, 0);
	bool isAttackValid = false;

	while (!isAttackValid)
	{
		std::cout << "Enter Ship # and Position for attack in the form of 0 A2" << "\n";
		std::getline(std::cin, input);

		std::istringstream inputStream(input);
			
		std::string shipNumber;
		inputStream >> shipNumber;

		int sNumber = atoi((shipNumber).c_str());
		
		std::string positionInput;
		inputStream >> positionInput;

		Position position = _board->ParsePositionFromInput(positionInput);

		if (position._x != -1 && (position._y >= 0))
			isAttackValid = _board->AttackWithShipIfPossible(sNumber, position);

		if (isAttackValid)
			attackPosition = position;
	}

	system("cls");

	//On va envoyer un message à l'autre joueur
	//NotifyShot(attackPosition);
}

void Player::MoveShip()
{
	std::string input;
	bool isMoveValid = false;

	while (!isMoveValid)
	{
		std::cout << "Enter Ship # and Move in the form of 0 -1" << "\n" 
			      << "Enter nothing if do not want to move a Ship" << "\n" ;

		std::getline(std::cin, input);

		std::istringstream inputStream(input);
			
		std::string shipNumber;
		inputStream >> shipNumber;

		if (!shipNumber.empty())
		{
			int sNumber = atoi((shipNumber).c_str());

			std::string moveInput;
			inputStream >> moveInput;

			int move = atoi((moveInput).c_str());

			if (move >= -2 && move <= 2)
				isMoveValid = _board->MoveShipIfPossible(sNumber, move);
		}
		else
			isMoveValid = true;
	}

	system("cls");
}


bool Player::PlaceShip(const Position position, Ship* ship, int orientation)
{
	return _board->PlaceShipIfPossible(position, ship, orientation);
}

void Player::SetOpponent(PlayerObserver* opponent)
{
	_opponent = opponent;
}

void Player::RemoveOpponent()
{
	_opponent = nullptr;
}

void Player::NotifyShot(const Position position)
{
	_opponent->OnNotify(position);
}

HitType Player::OnNotify(const Position position)
{
	// ici on va regarder si l'adversaire à touché quelque chose.
	return HitType::MISS;
}

void Player::DrawBoard()
{
	_board->DrawGrid();
}