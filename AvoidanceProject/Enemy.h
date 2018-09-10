#pragma once
#include "Base.h"

class Enemy : public Base
{
public:
	Enemy(int x, int y);
		void Update();
		void Render() const;
};