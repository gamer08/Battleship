#ifndef _POSITION_
#define _POSITION_

struct Position
{
private:
	
	// rend inaccessible le constructeur par copie et l'operateur d'assignation.
	Position(const Position&) = delete;
	Position& operator=(const Position& position) = delete;

public:
	int _x, _y;

	Position()
	{
		_x = _y = 0;
	}

	Position(int x, int y) : _x(x), _y(y)
	{}

	~Position()
	{}

};

#endif
