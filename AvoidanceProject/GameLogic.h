#pragma once
#include <vector>
#include <string>
#include <fstream>

#include "stdafx.h"

using namespace std;
#include "Console.h"

#include "Base.h"
#include "Player.h"
#include"Enemy.h"
class GameLogic
{
	vector<Base*> _objects;

	char border[121];
	int score = 0;
	int lives = 2;

public:
	GameLogic()
	{

		_objects.push_back(new Player(Console::WindowWidth() / 2, Console::WindowHeight() - 5));
		_objects.push_back(new Enemy(5, 3));
		_objects.push_back(new Enemy(20, 13));
		_objects.push_back(new Enemy(40, 8));
		_objects.push_back(new Enemy(60, 3));
		_objects.push_back(new Enemy(80, 8));
		_objects.push_back(new Enemy(100, 18));
		_objects.push_back(new Enemy(115, 13));
		_objects.push_back(new Enemy(12, 3));
		_objects.push_back(new Enemy(32, 8));
		_objects.push_back(new Enemy(50, 13));
		_objects.push_back(new Enemy(70, 3));
		_objects.push_back(new Enemy(90, 8));
		_objects.push_back(new Enemy(107, 3));

		memset(border, '_', 120);
		border[120] = '\0';
	}
	~GameLogic()
	{
		for (int i = 0; i < _objects.size(); ++i)
		{
			delete _objects[i];
		}
	}

	void Collision()
	{
		int playerX = 0, playerY = 0;
		int objectX = 0, objectY = 0;

		for (int i = 0; i < _objects.size(); ++i)
		{
			playerX = _objects[0]->GetX();
			playerY = _objects[0]->GetY();

			if (i > 0)
			{
				objectX = _objects[i]->GetX();
				objectY = _objects[i]->GetY();

			}
			if ((playerX == objectX) && (playerY == objectY))
				lives -= 1;
			else
			{
				int originalTick = 0;
				int newTick = GetTickCount();
				if (newTick > originalTick + 200)
				{
					score += 1;
					originalTick = newTick;
				}

			}
		}
	};

	void setPlayerName()
	{
		char buffer[32];
		char* name = nullptr;

		system("cls");
		cout << "What's your name Player? ";
		cin.getline(buffer, 32, '\n');


		int length = strlen(buffer) + 1;
		name = new char[length];

		strcpy_s(name, length, buffer);

		_objects[0]->SetName(name);

		system("cls");
	}

	void TextFileOut()
	{
		ofstream txtSaveOut;
		txtSaveOut.open("save.txt", ios::out | ios::app);

		if (!txtSaveOut)
		{
			txtSaveOut.open("save.txt", ios::trunc | ios::out);
			txtSaveOut.close();

			txtSaveOut.open("save.txt", ios::out | ios::app);
		}
		
		if (txtSaveOut.is_open())
		{
			char * playerName = _objects[0]->GetName();
			txtSaveOut << playerName << '\t' << score;
			txtSaveOut.close();
		}
		else
			cout << "File is already open.";

	}

	void Update()
	{
		for (int i = 0; i < _objects.size(); ++i)
		{
			_objects[i]->Update();
		}

		Collision();
	};

	void Render() const
	{
		Console::Lock(true);
		//Console::Clear();
		system("cls");

		//Display objects here
		Console::SetCursorPosition(1, 1);
		cout << _objects[0]->GetName();
		Console::SetCursorPosition((Console::WindowWidth() / 2) - 8, 1);
		cout << "Score: " << score << endl;
		cout << border << endl;
		for (int i = 0; i < _objects.size(); ++i)
		{
			_objects[i]->Render();
		}
		Console::SetCursorPosition(0, Console::WindowHeight() - 4);
		cout << border << endl;
		Console::SetCursorPosition(1, Console::WindowHeight() - 2);
		cout << "Lives: " << lives;
		Console::SetCursorPosition(Console::WindowWidth() - 18, Console::WindowHeight() - 2);
		cout << "Press ESC to Exit" << endl;
		Console::Lock(false);
		Sleep(20);

	}

	int ScoreLenth()
	{
		char buffer[32] = "Score: ";
		char scoreStr[8];

		sprintf_s(scoreStr, "%d", score);

		strcat_s(buffer, scoreStr);

		int length = strlen(buffer) + 1;

		return length;
	}

	void Play()
	{
		char saveScore;
		bool play = true;
		while (play)
		{
			Update();
			Render();

			if (GetAsyncKeyState(VK_ESCAPE) || lives == 0)
				play = false;
		};
		int gameOverLength = strlen("Game Over");
		int nameLength = strlen(_objects[0]->GetName());
		int enterToMain = strlen("Press ENTER to return to Main Menu.");
		int saveToFile = strlen("Do you wish to save your score?");

		Console::SetCursorPosition((Console::WindowWidth() / 2) - (gameOverLength / 2), (Console::WindowHeight() / 2) - 1);
		cout << "GAME OVER!";
		Console::SetCursorPosition((Console::WindowWidth() / 2) - (nameLength / 2), (Console::WindowHeight() / 2));
		cout << _objects[0]->GetName();
		Console::SetCursorPosition((Console::WindowWidth() / 2) - (ScoreLenth() / 2), (Console::WindowHeight() / 2) + 1);
		cout << "Score: " << score;
		Console::SetCursorPosition((Console::WindowWidth() / 2) - (saveToFile / 2), (Console::WindowHeight() / 2) + 3);
		cout << "Do you wish to save your score?  Y/N ";
		cin >> saveScore;
		saveScore = toupper(saveScore);
		if (saveScore == 'Y')
		{
			TextFileOut();
		}

		cin.clear();
		cin.ignore(INT_MAX, '\n');

		Console::SetCursorPosition((Console::WindowWidth() / 2) - (enterToMain / 2), (Console::WindowHeight() / 2) + 4);
		cout << "Press ENTER to return to Main Menu.";

		cin.clear();
		cin.ignore(INT_MAX, '\n');

		Console::ResetColor();
		Console::Clear();
	}
};