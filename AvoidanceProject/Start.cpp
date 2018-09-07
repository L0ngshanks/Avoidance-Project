#include "Start.h"

#include "MainMenu.h"

int main(int argc, char** argv)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(-1); //Important!

	MainMenu menu;

	menu.Menu();
};