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
	int lives = 3;

public:
	GameLogic()
	{
		_objects.push_back(new Player(Console::WindowWidth() / 2, Console::WindowHeight() - 5));
		_objects.push_back(new Enemy(5, 3));
		_objects.push_back(new Enemy(20, 13));
		_objects.push_back(new Enemy(40, 8));
		_objects.push_back(new Enemy(60, 18));
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

	void Update()
	{
		for (int i = 0; i < _objects.size(); ++i)
		{
			_objects[i]->Update();
		}
	}; 

	void Render() const
	{

		Console::Lock(true);
		//Console::Clear();
		system("cls");

		//Display objects here
		Console::SetCursorPosition(1, 1);
		cout << "Player" << endl;
		cout << border << endl;
		for (int i = 0; i < _objects.size(); ++i)
		{
			_objects[i]->Render();
		}
		Console::SetCursorPosition(0, Console::WindowHeight() - 4);
		cout << border << endl;
		Console::SetCursorPosition(1, Console::WindowHeight() - 2);
		cout << "Lives: " << lives << endl;
		Console::Lock(false);
		Sleep(10);

	}

	void Play()
	{
		bool play = true;
		while (play)
		{
			Update();
			Render();

			if (GetAsyncKeyState(VK_ESCAPE))
				play = false;
		};
		Console::ResetColor();
		Console::Clear();
	}
};