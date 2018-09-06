#pragma once
#include "Base.h"

class Enemy : public Base
{
	char enemyIcon = 'Y';
public:
	Enemy(int x, int y)
	{
		Base::SetX(x);
		Base::SetY(y);
	}

	void Update()
	{
		if (GetAsyncKeyState(VK_UP))
		{
			Base::SetY(Base::GetY() - 1);
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			Base::SetY(Base::GetY() + 1);
		}
	}
	void Render() const
	{
		//Display objects here
		Console::SetCursorPosition(Base::GetX(), Base::GetY());
		Console::ForegroundColor(FOREGROUND_RED);
		cout << enemyIcon;
		Console::ResetColor();
	};

};