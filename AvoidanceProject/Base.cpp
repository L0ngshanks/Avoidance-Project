#include "Base.h"

#include "Console.h"
using namespace System;

	int pos_x = 0;
	int pos_y = 0;

	char* playerName = nullptr;
	char characterDisplay;

	Base::Base(int x, int y)
	{
		SetX(x);
		SetY(y);
	}
	int Base::GetX() const
	{
		return pos_x;
	};

	int Base::GetY() const
	{
		return pos_y;
	};

	void Base::SetX(int x)
	{
		if (x >= 0 && x < Console::WindowWidth())
			pos_x = x;
	};

	void Base::SetY(int y)
	{
		if (y >= 3)
		{
			pos_y = y;
			if (y > Console::WindowHeight() - 4)
				pos_y = 3;
		}
	};

	void Base::SetSymbol(char symbol)
	{
		characterDisplay = symbol;
	}

	void Base::SetName(char* name)
	{
		playerName = name;
	}

	char* Base::GetName()
	{
		return playerName;
	}

	void Base::Update()
	{
		if (GetAsyncKeyState(VK_LEFT))
		{
			SetX(pos_x - 1);
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			SetX(pos_x + 1);
		}
		if (GetAsyncKeyState(VK_UP))
		{
			SetY(pos_y - 1);
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			SetY(pos_y + 1);
		}
	};

	void Base::Render() const
	{

		//Display objects here
		Console::SetCursorPosition(pos_x, pos_y);
		cout << characterDisplay;

	};

