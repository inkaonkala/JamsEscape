/* * * * * * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * **
 * Author: Inka Niska												*
 * Email : inkaisinka@live.com										*
 *																	*
 *       (\(\  														*
 *      ( -.-)   Coding time...										*
 *     o_(")(") 													*
 *																	*
 *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * * * */

#include "Fence.hpp"

Fence::Fence(float startX)
{
	if (!tex.loadFromFile("assets/fence.png"))
		std::cerr << "Could not download Fence texture\n";

	sprite.setTexture(tex);
	sprite.setPosition(startX, 420.f);
	sprite.setScale(0.5f, 0.5f);
}

void Fence::update(float gSpeed)
{
	sprite.move(speed * gSpeed, 0.f);
}

void Fence::draw(sf::RenderWindow& win)
{
	win.draw(sprite);
}

sf::FloatRect Fence::getHitbox() const 
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