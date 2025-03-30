/* * * * * * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * **
 * Author: Inka Niska												*
 * Email : inkaisinka@live.com										*
 *																	*
 *       (\(\  														*
 *      ( -.-)   Coding time...										*
 *     o_(")(") 													*
 *																	*
 *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * * * */

#include "Fence2.hpp"

Fence2::Fence2(float startX)
{
	if (!tex.loadFromFile("assets/fence2.png"))
		std::cerr << "Could not download Fence2 texture\n";

	sprite.setTexture(tex);
	sprite.setPosition(startX, 420.f);
	sprite.setScale(0.5f, 0.5f);
}

void Fence2::update(float gSpeed)
{
	sprite.move(speed * gSpeed, 0.f);
}

void Fence2::draw(sf::RenderWindow& win)
{
	win.draw(sprite);
}

sf::FloatRect Fence2::getHitbox() const 
{
	sf::FloatRect bounds = sprite.getGlobalBounds();

	float shrinkX = 80.f;
	float shrinkY = 80.f;

	bounds.left += shrinkX / 2.f;
	bounds.top += shrinkY / 2.f;
	bounds.width -= shrinkX;
	bounds.height -= shrinkY;

	return bounds;
}