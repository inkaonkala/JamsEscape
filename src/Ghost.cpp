/* * * * * * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * **
 * Author: Inka Niska												*
 * Email : inkaisinka@live.com										*
 *																	*
 *       (\(\  														*
 *      ( -.-)   Coding time...										*
 *     o_(")(") 													*
 *																	*
 *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * * * */

#include "Ghost.hpp"
#include "gameBase.hpp"

Ghost::Ghost(float startX, float y)
{
	if (!tex1.loadFromFile("assets/ghost1.png"))
		std::cerr << "Could not download Ghost texture\n";
	if (!tex2.loadFromFile("assets/ghost2.png"))
		std::cerr << "Could not download Ghost texture\n";

	sprite.setTexture(tex1);
	sprite.setPosition(startX, startY);
	sprite.setScale(0.4f, 0.4f);
	startY = y - 220.f;
}

void Ghost::update(float gSpeed)
{
	sprite.move(speed * gSpeed, 0.f);

	// movement
	float time = animationClock.getElapsedTime().asSeconds();
	float offset = std::sin(time * 2.f) * floatRange;
	sprite.setPosition(sprite.getPosition().x, startY + offset);

	//animation
	if (animationClock.getElapsedTime().asSeconds() > animationDelay)
	{
		atFirstFrame = !atFirstFrame;
		sprite.setTexture(atFirstFrame ? tex1 : tex2);
		animationClock.restart();
	}
}

void Ghost::draw(sf::RenderWindow& win)
{
	win.draw(sprite);
}

sf::FloatRect Ghost::getHitbox() const 
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