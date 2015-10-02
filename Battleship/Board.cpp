#include "Board.h"
#include <iostream>
#include <ctype.h>

Board::Board(int order)
{
	_order = order;

	_grid = new Cell*[_order];

	for (int i = 0; i < order; i++)
		_grid[i] = new Cell[_order];

}

Board::~Board()
{
	for (int i = 0; i < _order; i++)
		delete[] _grid[i];

	delete[] _grid;
}

void Board::DrawGrid()
{
	for (int row = 0; row < _order; row++)
	{
		for (int col = 0; col < _order; col++)
			std::cout << _grid[row][col]._displayCharacter << " ";

		std::cout << "\n";
	}

	std::cout << "\n";
}

void Board::AddShip(Ship* ship)
{
	////Ajoute le navire dans le vecteur s'il n'y est pas.
	//if (std::find(_ships.begin(), _ships.end(), ship) == _ships.end())
	//	_ships.push_back(ship);
}

bool Board::PlaceShipIfPossible(const Position position, Ship* ship, int orientation)
{
	AddShip(ship);

	bool shipIsPlaced = false;
	switch (orientation)
	{
	case 0: // Horizontal

		if (position._y + ship->GetLength() < _order)
		{
			if (!PlaceShipIfEnoughSpace(position, ship, orientation)) // si pas assez de place on essaie de l'autre sens. 
			{
				if (position._x + ship->GetLength() < _order)
					shipIsPlaced = PlaceShipIfEnoughSpace(position, ship, 1);
			}
			else
				shipIsPlaced = true;
		}
		else if (position._x + ship->GetLength() < _order)
			shipIsPlaced = PlaceShipIfEnoughSpace(position, ship, 1);

		break;

	case 1: // Vertical

		if (position._x + ship->GetLength() < _order)
		{
			if (!PlaceShipIfEnoughSpace(position, ship, orientation)) // si pas assez de place on essaie de l'autre sens. 
			{
				if (position._y + ship->GetLength() < _order)
					shipIsPlaced = PlaceShipIfEnoughSpace(position, ship, 0);
			}
			else
				shipIsPlaced = true;
		}
		else if (position._y + ship->GetLength() < _order)
			shipIsPlaced = PlaceShipIfEnoughSpace(position, ship, 0);

		break;

	default:

		break;
	}
	return shipIsPlaced;
}

bool Board::PlaceShipIfEnoughSpace(const Position position, Ship* ship, int orientation)
{
	bool shipIsPlaced = false;
	bool enoughPlace = true;

	switch (orientation)
	{
	case 0: // Horizontal

		for (int col = position._y; col < (position._y + ship->GetLength()); col++)
		{
			if (_grid[position._x][col]._ship)
			{
				enoughPlace = false;
				break;
			}
		}

		if (enoughPlace)
		{
			_ships.push_back(ship);
			ship->SetPosition(position);
			ship->SetOrientation(0);

			for (int col = position._y; col < (position._y + ship->GetLength()); col++)
			{
				_grid[position._x][col]._displayCharacter = 'O';
				_grid[position._x][col]._ship = ship;
			}

			shipIsPlaced = true;
		}
		break;

	case 1: // vertical

		for (int row = position._x; row < (position._x + ship->GetLength()); row++)
		{
			if (_grid[row][position._y]._ship)
			{
				enoughPlace = false;
				break;
			}
		}

		if (enoughPlace)
		{
			_ships.push_back(ship);
			ship->SetPosition(position);
			ship->SetOrientation(1);

			for (int row = position._x; row < (position._x + ship->GetLength()); row++)
			{
				_grid[row][position._y]._displayCharacter = 'O';
				_grid[row][position._y]._ship = ship;
			}

			shipIsPlaced = true;
		}
		break;

	default:
		break;
	}

	return shipIsPlaced;
}

Position Board::ParsePositionFromInput(std::string input)
{
	char line = input.at(0);
	int column = std::atoi((input.substr(1)).c_str());

	line = toupper(line); // Met en majuscule pour le test

	Position position;

	switch (line)
	{
	case 'A':
		position = Position(0, column);
		break;
	case 'B':
		position = Position(1, column);
		break;
	case 'C':
		position = Position(2, column);
		break;
	case 'D':
		position = Position(3, column);
		break;
	case 'E':
		position = Position(4, column);
		break;
	case 'F':
		position = Position(5, column);
		break;
	case 'G':
		position = Position(6, column);
		break;
	case 'H':
		position = Position(7, column);
		break;
	case 'I':
		position = Position(8, column);
		break;
	case 'J':
		position = Position(9, column);
		break;
	default:
		position = Position(-1, -1);
		break;
	}

	return position;
}

bool Board::AttackWithShipIfPossible(int shipNumber, const Position position)
{
	if (shipNumber < 0 || (shipNumber >= _ships.size()) || _ships[shipNumber]->IsSink())
		return false;

	return _ships[shipNumber]->CanAttackAtPosition(position);
}

bool Board::MoveShipIfPossible(int shipNumber, int move)
{
	if (shipNumber < 0 || (shipNumber >= _ships.size()) || _ships[shipNumber]->IsSink())
		return false;

	Ship* ship = _ships[shipNumber];
	Position originalPosition = ship->GetPosition();
	Position newPosition = Position(originalPosition);
	int length = ship->GetLength();

	bool isMoveValid = true;

	switch (_ships[shipNumber]->GetOrientation())
	{
	case 0:
		newPosition._y += move;

		// regarde s'il y a de la place
		if ((newPosition._y + length >=0 ) && ((newPosition._y + length) < _order))
		{
			for (int i = newPosition._y; i < (newPosition._y + length); i++)
			{
				if (_grid[originalPosition._x][i]._ship && (_grid[originalPosition._x][i]._ship != ship))
				{
					isMoveValid = false;
					break;
				}
			}

			//Deplace le navire
			if (isMoveValid)
			{
				for (int i = newPosition._y; i < (newPosition._y + length); i++)
				{
					_grid[originalPosition._x][i]._displayCharacter = _grid[originalPosition._x][i - move]._displayCharacter;
					_grid[originalPosition._x][i]._ship = _grid[originalPosition._x][i - move]._ship;
				}

				if (move>0)
				{
					for (int i = originalPosition._y; i < newPosition._y; i++)
					{
						_grid[originalPosition._x][i]._displayCharacter = '_';
						_grid[originalPosition._x][i]._ship = nullptr;
					}
				}
				else
				{
					for (int i = (originalPosition._y + length - 1); i >((originalPosition._y + length - 1) + move); i--)
					{
						_grid[originalPosition._x][i]._displayCharacter = '_';
						_grid[originalPosition._x][i]._ship = nullptr;
					}
				}
				ship->SetPosition(newPosition);
			}
		}
		else
			isMoveValid = false;

		break;

	case 1:
		newPosition._x += move;

		// regarde s'il y a de la place
		if ((newPosition._x + length >=0 ) && ((newPosition._x + length) < _order))
		{
			for (int i = newPosition._x; i < (newPosition._x + length); i++)
			{
				if (_grid[i][originalPosition._y]._ship && (_grid[i][originalPosition._y]._ship != ship))
				{
					isMoveValid = false;
					break;
				}
			}

			//Deplace le navire
			if (isMoveValid)
			{
				for (int i = newPosition._x; i < (newPosition._x + length); i++)
				{
					_grid[i][originalPosition._y]._displayCharacter = _grid[i - move][originalPosition._y]._displayCharacter;
					_grid[i][originalPosition._y]._ship = _grid[i - move][originalPosition._y]._ship;
				}

				if (move>0)
				{
					for (int i = originalPosition._x; i < newPosition._x; i++)
					{
						_grid[i][originalPosition._y]._displayCharacter = '_';
						_grid[i][originalPosition._y]._ship = nullptr;
					}
				}
				else
				{
					for (int i = (originalPosition._x + length - 1); i >((originalPosition._x + length - 1) + move); i--)
					{
						_grid[i][originalPosition._y]._displayCharacter = '_';
						_grid[i][originalPosition._y]._ship = nullptr;
					}
				}
				ship->SetPosition(newPosition);
			}
		}
		else
			isMoveValid = false;

		break;
	}
	return isMoveValid;
}