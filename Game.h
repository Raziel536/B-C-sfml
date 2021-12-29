#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "Base.h"
#include "Enemy.h"
#include "Map.h"
#include "Player.h"
#include "Textis.h"



class game : private sf::NonCopyable
{
private:
	bool gameOvered;
	bool gameStarted;
	int playerKills;

	sf::RenderWindow gameWindow;
	Base myBase;
	Base enemyBase;

	Map map;

	Player me;
	Enemy* pack_of_enemies;

	
	Textis gameStart;
	Textis gameOver;
	Textis wasted;
	Textis win;
	

public:
	game();

	void events_process();
	void update(const float &time);
	void render();
};

