#include "Enemy.h"
#include "Base.h"

#include "stdafx.h"

	char enemyIcon = 'Y';
	Enemy::Enemy(int x, int y) : Base(x,y)
	{
		SetX(x);
		SetY(y);
	}

	void Enemy::Update()
	{
		int originalTick = 0;
		int newTick = GetTickCount();
		if (newTick > originalTick + 200)
		{
			Base::SetY(Base::GetY() + 1);
			originalTick = newTick;
		}

		/*if (GetAsyncKeyState(VK_UP))
		{
			Base::SetY(Base::GetY() - 1);
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			Base::SetY(Base::GetY() + 1);
		}*/
	}
	void Enemy::Render() const
	{
		//Display objects here
		Console::SetCursorPosition(Base::GetX(), Base::GetY());
		Console::ForegroundColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << enemyIcon;
		Console::ResetColor();
	};
