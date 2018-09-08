#include "MainMenu.h"

#include <iostream>

#include "Validation.h"

using namespace std;

void MainMenu::Menu()
{
	Validation valid;

	enum menuOptions {NewGame = 1, Load_txt, Load_bin, Save_txt, Save_bin, Max_Options = 9 };
	int selection = 0;

	while (selection != 9)
	{

		cout << "Avoidance Project" << endl;
		cout << "--------------------------" << endl;
		cout << "1) New Game" << endl;
		cout << "--------------------------" << endl;
		cout << "2) Load Text Save" << endl;
		cout << "3) Load Binary Save" << endl;
		cout << "--------------------------" << endl;
		cout << "4) Save as a Text save" << endl;
		cout << "5) Save as a Binary save" << endl;
		cout << "--------------------------" << endl;
		cout << "9) Exit" << endl;

		selection = valid.IntValidation("Selection: ");

		menuOptions options = menuOptions(selection);


		switch (options)
		{
		case NewGame:
		{
			GameLogic game;
			game.setPlayerName();
			game.Play();
			break;
		}
		case Load_txt:
			break;
		case Load_bin:
			break;
		case Save_txt:
			break;
		case Save_bin:
			break;
		case Max_Options:
			return;
		default:
			break;
		}
	}
};