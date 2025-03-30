/* * * * * * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * **
 * Author: Inka Niska												*
 * Email : inkaisinka@live.com										*
 *																	*
 *       (\(\  														*
 *      ( -.-)   Coding time...										*
 *     o_(")(") 													*
 *																	*
 *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * * * */

#include "gameBase.hpp"
#include "Piggy.hpp"
#include "Obs.hpp"
#include "Beautify.hpp"


void gameBase::updateMenu()
{
	menuText.setString("Jam's Escape \n	Press Enter to start");
	
}

void gameBase::updateGameplay()
{
	spawnObstacle();
	updateBeauty();
	back.updateFarm();

	if (!piggy.isTimeFrozen())
	{
		//back.loopTheSky();

		//SPAWN ENEMIES
		for (auto& o : obs)
			o->update(gameSpeed);
	}

	piggy.updateMoveMode(!piggy.isTimeFrozen());
	pointsTex.setString("Oinks: " + std::to_string(piggy.getPoints()));
	checkCollisions();


	if (speedUpTimer.getElapsedTime().asSeconds() > 15.f) // increase in every 15sec now
	{
		gameSpeed += 0.1f;
		speedUpTimer.restart();
	}
}

void gameBase::updateStart()
{
	piggy.start();
	if (piggy.getPosition().x < 900.f)
	{
		this->state = GameState::PlayingMove;
		back.triggerFarmSlide();
	}
}

void gameBase::updateBeauty()
{
	cloud.update(gameSpeed);

	if (showFlower)
	{
		flower.update(gameSpeed);
		if (flower.getX() > 1380.f) // You can write `getWidth()`
			showFlower = false;
	}
	else if (flowerTimer.getElapsedTime().asSeconds() > 10.f)
	{
		int r = rand() % 100;
		if (r < 50)
		{
			showFlower = true;
			flower.reset();

		}
		flowerTimer.restart();
	}
}