#include "Player.h"
#include "Ship.h"
#include <vector>
#include <memory>
#include "BattleshipGame.h"

//#include <iostream>
//#include <sstream>
//#include <string>

int main()
{
	BattleshipGame* game = new BattleshipGame();
	game->Start();
	game->Run();

	
	/*Va etre utilisé pour rendre le code plus sécuritaire.*/
	//std::shared_ptr<BattleshipGame> g(new BattleshipGame);

	

	
	/*Player* player = new Player();

	std::vector<Ship*> ships;

	ships.push_back(new Ship(1, 1));
	ships.push_back(new Ship(2, 1));

	player->PlaceShips(ships);*/

	/*int nb = ships.size();
	
	
	std::string input;
	bool shipPlaced = false;
	for (int index = 0; index < nb; index++)
	{
		while (!shipPlaced)
		{
			std::cout << "Enter position and orientation for ship " << (index + 1) << "in the for of A2 0" << "\n";
			std::getline(std::cin, input);

			std::istringstream inputStream(input);
			
			std::string positionInput;
			inputStream >> positionInput;

			std::string orientationInput;
			inputStream >> orientationInput;

			int orientation = atoi((orientationInput).c_str());

			
		}
	}*/

	return 0;
}

