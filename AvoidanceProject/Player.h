#pragma once

#include "Base.h"

class Player : public Base
{
public:
	Player(int x, int y);

	void Update();
	void Render() const;

};
