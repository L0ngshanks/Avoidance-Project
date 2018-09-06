#pragma once

#include "Console.h"
using namespace System;

class Base
{
	int pos_x;
	int pos_y;

	char characterDisplay;
public:
	Base()
	{};

	Base(int x, int y)
	{
		SetX(x);
		SetY(y);
	}
	int GetX() const
	{
		return pos_x;
	};

	int GetY() const
	{
		return pos_y;
	};

	void SetX(int x)
	{
		if (x >= 0 && x < Console::WindowWidth())
			pos_x = x;
	};

	void SetY(int y)
	{
		if (y >= 0)
		{
			pos_y = y;
			if (y > Console::WindowHeight())
				pos_y = 0;
		}
	};

	void SetSymbol(char symbol)
	{
		characterDisplay = symbol;
	}

	void virtual Update()
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

	virtual void Render() const
	{

		//Display objects here
		Console::SetCursorPosition(pos_x, pos_y);
		cout << characterDisplay;

	};
};

