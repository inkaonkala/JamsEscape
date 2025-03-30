/* * * * * * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * **
 * Author: Inka Niska												*
 * Email : inkaisinka@live.com										*
 *																	*
 *       (\(\  														*
 *      ( -.-)   Coding time...										*
 *     o_(")(") 													*
 *																	*
 *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * * * */

#include "backround.hpp"
#include "gameBase.hpp"

void Backround::setupTheBack()
{
	if (!br.loadFromFile("assets/back2.png"))
		std::cerr << "Could not download the backround\n";
	if (!startBr.loadFromFile("assets/rules.png"))
		std::cerr << "No background with rules in images\n";
	if (!farmTex.loadFromFile("assets/farm.png"))
		std::cerr << "No farm tex to be found\n";
	else 
		farm.setTexture(farmTex);

	back1.setTexture(br);
	back2.setTexture(br);
	back3.setTexture(startBr);

	back1.setPosition(-800.f, 0.f);
	back2.setPosition(-400.f, 0.f);
	back3.setPosition(500.f, 0.f);

	farm.setTexture(farmTex);
	farm.setScale(0.8f, 0.8f);
	farm.setPosition(1400.f, 300.f);
}

void Backround::draw(sf::RenderWindow& win)
{
		win.draw(back2);
		win.draw(back3);
}

void Backround::triggerFarmSlide()
{
	farmSliding = true;
}

void Backround::updateFarm()
{
	if (farmSliding)
	{
		farm.move(5.f, 0.f);
		if (farm.getPosition().x < -farm.getGlobalBounds().width)
			farmSliding = false;
	}
}

void Backround::drawFarm(sf::RenderWindow& win, GameState state)
{
	if (state == GameState::PlayingStart || farmSliding)
		win.draw(farm);
}

void Backround::resetFarm()
{
	farmSliding = false;
	farm.setPosition(1000.f, 300.f);
}

//void Backround::loopTheSky()
//{
//	back1.move(scrollSpeed, 0.f);
//	back2.move(scrollSpeed, 0.f);

//float width = br.getSize().x;

//back1.move(-scrollSpeed, 0.f);
//back2.move(-scrollSpeed, 0.f);

//if (back1.getPosition().x <= -width)
//	back1.setPosition(back2.getPosition().x + width, 0.f);

//if (back2.getPosition().x <= -width)
//	back2.setPosition(back1.getPosition().x + width, 0.f);
//}


