#include "Player.h"
#include "Base.h"

#include "stdafx.h"

char playerIcon = 'X';

	Player::Player(int x, int y) : Base(x,y)
	{
		SetX(x);
		SetY(y);
	}

	void Player::Update()
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
	void Player::Render() const
	{
		//Display objects here
		Console::SetCursorPosition(Base::GetX(), Base::GetY());
		Console::ForegroundColor(FOREGROUND_GREEN);
		cout << playerIcon;
		Console::ResetColor();
		//Sleep(10);

	};
