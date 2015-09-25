#ifndef _POSITION_
#define _POSITION_

struct Position
{
private:
	
	// rend l'operateur d'assignation.
	
	//Position& operator=(const Position& position) = delete;

public:
	int _x, _y;

	Position()
	{
		_x = _y = 0;
	}

	Position(int x, int y) : _x(x), _y(y)
	{}
	
	Position(const Position& pos)
	{
		_x = pos._x;
		_y = pos._y;
	}

	Position& operator=(const Position& position)
	{
		this->_x = position._x;
		this->_y = position._y;

		return *this;
	}

	~Position()
	{}

};

#endif
