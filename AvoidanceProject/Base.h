#pragma once

class Base
{
private:

public:
	Base(int x, int y);
	int GetX() const;
	int GetY() const;
	void SetX(int x);
	void SetY(int y);
	void SetSymbol(char symbol);
	void SetName(char* name);
	char* GetName();
	void virtual Update();
	void virtual Render() const;
};
