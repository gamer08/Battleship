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
			ship->SetPosition(position);
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
			ship->SetPosition(position);
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