#include "Game.h"
#include <SFML/Window/Event.hpp>

game::game():
gameWindow(sf::VideoMode(720, 670), "BattleCityLife?!"),
gameStart( 90, 330, "Press ENTER to start"),
gameOver(250, 300, "Game Over"),
wasted(260, 350, "WASTED"), 
win(260, 350,"Player Wins"),
myBase(336, 600),
enemyBase(336, 120)

{
	playerKills = 0;
	gameOvered = false;
	gameStarted = false;

	Clock clock;
	pack_of_enemies = new Enemy[4]{ Enemy(52,31),Enemy(147,391),Enemy(628,31), Enemy(532, 391) };

	while (gameWindow.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		events_process();
		if (Keyboard::isKeyPressed(Keyboard::Q))
		{
			gameWindow.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Enter))
		{
			gameStarted = true;
		}
		if (gameStarted && !gameOvered)
		{
			update(time);
		}
		render();
	}

}


void game::events_process()
{
	sf::Event event;
	while (gameWindow.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			gameWindow.close();
			break;
		}
	}
}


void game::update(const float& time)
{
	for(int i=0; i<4; ++i)
	{
		if (!pack_of_enemies[i].life)
			++playerKills;
		else
		{
			playerKills = 0;
			break;
		}
	}

	if(playerKills==4 || !enemyBase.life)
	{
		gameOvered = true;
	}

	if (!me.life)
		gameOvered = true;

	bool collision;
	for(int i = 0; i < 4; ++i)
	{
		collision = me.tank_Sprite.getGlobalBounds().intersects(pack_of_enemies[i].tank_Sprite.getGlobalBounds());
		if (collision)
			break;
	}

	if(me.life)
	{
		me.update(time, map, collision);
	}

	for(int i = 0; i < 4; ++i)
	{
		if(pack_of_enemies[i].life)
		{
			pack_of_enemies[i].update(time, map, collision);

			if(pack_of_enemies[i].bullet.bullet_Sprite.getGlobalBounds().intersects(me.tank_Sprite.getGlobalBounds())
				&& pack_of_enemies[i].bullet.present)
			{
				me.health -= 100;
				if(me.health <= 0)
					me.collapse();
				pack_of_enemies[i].bullet.present = false;
			}

			if(pack_of_enemies[i].bullet.bullet_Sprite.getGlobalBounds().intersects(myBase.base_Sprite.getGlobalBounds())
				&& pack_of_enemies[i].bullet.present)
			{
				myBase.life = false;
				gameOvered = true;
			}
			if(me.bullet.bullet_Sprite.getGlobalBounds().intersects(pack_of_enemies[i].tank_Sprite.getGlobalBounds())
				&& me.bullet.present)
			{
				pack_of_enemies[i].health -= 100;
				if(pack_of_enemies[i].health <= 0)
					pack_of_enemies[i].collapse();
				me.bullet.present = false;
			}
		}
	}
	if(me.bullet.bullet_Sprite.getGlobalBounds().intersects(myBase.base_Sprite.getGlobalBounds()) 
		&& me.bullet.present)
	{
		myBase.life = false;
		gameOvered = true;
	}
	if(me.bullet.bullet_Sprite.getGlobalBounds().intersects(enemyBase.base_Sprite.getGlobalBounds())
		&& me.bullet.present)
	{
		enemyBase.life = false;
		gameOvered = true;
	}


}

void game::render()
{
	gameWindow.clear();
	map.draw(gameWindow);
	if (me.life)
		gameWindow.draw(me.tank_Sprite);

	if (me.bullet.present)
		gameWindow.draw(me.bullet.bullet_Sprite);

	for (int i = 0; i < 4; ++i)
	{
		if (pack_of_enemies[i].bullet.present)
			gameWindow.draw(pack_of_enemies[i].bullet.bullet_Sprite);

		if (pack_of_enemies[i].life)
			gameWindow.draw(pack_of_enemies[i].tank_Sprite);
	}

	if (enemyBase.life)
		gameWindow.draw(enemyBase.base_Sprite);

	if (myBase.life)
		gameWindow.draw(myBase.base_Sprite);

	if(!gameStarted)
	{
		gameStart.print(gameWindow);
	}
	if(gameOvered)
	{
		gameOver.print(gameWindow);
		if (!myBase.life || !me.life)
			wasted.print(gameWindow);
		else
		{
			win.print(gameWindow);
		}
	}
	gameWindow.display();
}
