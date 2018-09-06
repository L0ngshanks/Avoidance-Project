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

	int lives = 3;
public:
	GameLogic()
	{
		Base* player = new Player(5, 5);
		Base* enemy = new Enemy(10, 10);

		_objects.push_back(player);
		_objects.push_back(enemy);
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
		Console::Clear();

		//Display objects here
		Console::SetCursorPosition(1, 1);
		cout << "Player" << endl;
		for (int i = 0; i < Console::WindowWidth(); ++i)
		{
			cout << "_";
		}
		cout << endl;
		for (int i = 0; i < _objects.size(); ++i)
		{
			_objects[i]->Render();
		}
		Console::SetCursorPosition(0, Console::WindowHeight() - 4);
		for (int i = 0; i < Console::WindowWidth(); ++i)
		{
			cout << "_";
		}
		Console::SetCursorPosition(1, Console::WindowHeight() - 2);
		cout << "Lives: " << lives << endl;
		Console::Lock(false);
		Sleep(25);

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