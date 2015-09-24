#include "Board.h"

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