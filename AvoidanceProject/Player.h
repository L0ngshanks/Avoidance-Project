#pragma once

#include "Base.h"

class Player : public Base
{
	char playerIcon = 'X';

	char* playerName = nullptr;

public:
	Player(int x, int y)
	{
		Base::SetX(x);
		Base::SetY(y);
	}

	void Update()
	{
		int originalTick = 0;
		int newTick = GetTickCount();
		if (newTick > originalTick + 30)
		{
			if (GetAsyncKeyState(VK_LEFT))
			{
				Base::SetX(Base::GetX() - 1);
			}
			if (GetAsyncKeyState(VK_RIGHT))
			{
				Base::SetX(Base::GetX() + 1);
			}
			originalTick = newTick;
		}
	}
	void Render() const
	{
		//Display objects here
		Console::SetCursorPosition(Base::GetX(), Base::GetY());
		Console::ForegroundColor(FOREGROUND_GREEN);
		cout << playerIcon;
		Console::ResetColor();
		//Sleep(10);

	};

};
