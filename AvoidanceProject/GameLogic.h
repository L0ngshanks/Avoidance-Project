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
		for (int i = 0; i < _objects.size(); ++i)
		{
			_objects[i]->Render();
		}

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