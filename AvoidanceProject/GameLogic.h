#pragma once
#include <vector>
#include <string>
#include <fstream>

#include "stdafx.h"

class GameLogic
{
private:	

public:
	GameLogic();
	~GameLogic();

	void Collision();
	int ScoreLength();
	void SetPlayerName();
	void TextFileOut();
	void TextFileLoad();

	void Update();
	void Render() const;
	void Play();

};