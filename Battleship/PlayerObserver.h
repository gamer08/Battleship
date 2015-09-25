#ifndef _PLAYEROBSERVER_
#define _PLAYEROBSERVER_

//Une variante du design pattern Observer, à la fois l'orserveur et le sujet

#include "HitType.h"

struct Position; 

class PlayerObserver
{

private:
	PlayerObserver& operator=(const PlayerObserver& observer) = delete;

protected:	
	PlayerObserver(){}
	
	PlayerObserver(const PlayerObserver& observer);

public:
	virtual HitType OnNotify(const Position position) = 0;
	virtual void SetOpponent(PlayerObserver* opponent) = 0;
	virtual void RemoveOpponent() = 0;
	virtual ~PlayerObserver(){}
};

#endif