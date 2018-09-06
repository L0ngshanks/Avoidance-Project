#pragma once

#include "Base.h"

class Player : public Base
{
	char playerIcon = 'X';

public:
	Player(int x, int y)
	{
		Base::SetX(x);
		Base::SetY(y);
	}

	void Update()
	{
		if (GetAsyncKeyState(VK_LEFT))
		{
			Base::SetX(Base::GetX() - 1);
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			Base::SetX(Base::GetX() + 1);
		}
	}
	void Render() const
	{
		//Display objects here
		Console::SetCursorPosition(Base::GetX(), Base::GetY());
		Console::ForegroundColor(FOREGROUND_GREEN);
		cout << playerIcon;

	};

};
