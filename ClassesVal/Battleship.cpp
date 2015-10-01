#include "Player.h"
#include "Ship.h"
#include <vector>
#include <memory>
#include "BattleshipGame.h"
#include <iostream> // pour le cout/cin
#include <sstream> // pour le getline

//#include <iostream>
//#include <sstream>
//#include <string>

int main()
{
	std::cout << "Bonjour et bienvenue dans le jeu de la bataille navale!"<<"\n \n";
	

	std::string input;
	bool choiceGood = false; // booleen qui sert a savoir que l'utilisateur a bien entrer un nb entre 1 et 2
	

	while (!choiceGood)
	{
		std::cout << "Choisissez le choix 1 pour jouer contre un autre joueur \n et le choix 2 pour jouer contre l'ordinateur" << "\n";

		std::getline(std::cin, input);
		std::istringstream inputStream(input);


		std::string choiceInput;
		inputStream >> choiceInput;

		int choice = atoi((choiceInput).c_str());

		if (choice == 1)
		{
			std::cout << "Vous avez choisi de jouer contre un autre joueur" << "\n";
			choiceGood = true;
			std::system("PAUSE");

		}

		else if (choice == 2)
		{
			std::cout << "Vous avez choisi de jouer contre l'ordinateur" << "\n";
			choiceGood = true;
			std::system("PAUSE");
		}
	}
	

	
	

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

