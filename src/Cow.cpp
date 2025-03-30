/* * * * * * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * **
 * Author: Inka Niska												*
 * Email : inkaisinka@live.com										*
 *																	*
 *       (\(\  														*
 *      ( -.-)   Coding time...										*
 *     o_(")(") 													*
 *																	*
 *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * * * */

#include "Cow.hpp"

Cow::Cow(float startX)
{
	if (!tex1.loadFromFile("assets/cow1.png"))
		std::cerr << "Could not download cow1 texture\n";
	if (!tex2.loadFromFile("assets/cow2.png"))
		std::cerr << "Could not download cow2 texture\n";

	sprite.setTexture(tex1);
	sprite.setPosition(startX, 390.f);
	sprite.setScale(0.7f, 0.7f);
}

void Cow::update(float gSpeed)
{
	sprite.move(speed * gSpeed, 0.f);

	if (animationClock.getElapsedTime().asSeconds() > animationDelay)
	{
		if (useTex1)
			sprite.setTexture(tex2);
		else
			sprite.setTexture(tex1);
		useTex1 = !useTex1;
		animationClock.restart();
	}
}

void Cow::draw(sf::RenderWindow& win)
{
	win.draw(sprite);
}

sf::FloatRect Cow::getHitbox() const 
{
	sf::FloatRect bounds = sprite.getGlobalBounds();

	float shrinkX = 100.f;
	float shrinkY = 100.f;

	bounds.left += shrinkX / 2.f;
	bounds.top += shrinkY / 2.f;
	bounds.width -= shrinkX;
	bounds.height -= shrinkY;

	return bounds;
}