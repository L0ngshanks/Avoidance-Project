#pragma once
#include <vector>

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
	int lives = 10;

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
		cout << "Player";
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

	void Play()
	{
		bool play = true, scoreScreen = true;
		while (play)
		{
			Update();
			Render();

			if (GetAsyncKeyState(VK_ESCAPE) || lives == 0)
				play = false;
		};

		Console::SetCursorPosition((Console::WindowWidth() / 2) - 5, (Console::WindowHeight() / 2) - 1);
		cout << "GAME OVER!";
		Console::SetCursorPosition((Console::WindowWidth() / 2) - 3, (Console::WindowHeight() / 2));
		cout << "Player";
		Console::SetCursorPosition((Console::WindowWidth() / 2) - 4, (Console::WindowHeight() / 2) + 1);
		cout << "Score: " << score;
		Console::SetCursorPosition((Console::WindowWidth() / 2) - 18, (Console::WindowHeight() / 2) + 3);
		cout << "Press ENTER to return to Main Menu.";

		_getch();

		Console::ResetColor();
		Console::Clear();
	}
};