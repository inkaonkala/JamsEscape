/* * * * * * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * **
 * Author: Inka Niska												*
 * Email : inkaisinka@live.com										*
 *																	*
 *       (\(\  														*
 *      ( -.-)   Coding time...										*
 *     o_(")(") 													*
 *																	*
 *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * * * */

#include "Beautify.hpp"

Beautify::Beautify(const std::string& path, float y, float scale, float spd)
{
	if (!tex.loadFromFile(path))
		std::cerr << "Failed to load beauty image\n";
	else
		std::cout << "BEUTY loaded" << std::endl;

	sprite.setTexture(tex);
	sprite.setScale(scale, scale);
	sprite.setPosition(-30.f, y);
	speed = spd;
}

void Beautify::update(float gSpeed)
{
	sprite.move(speed * gSpeed, 0.f);
	if (sprite.getPosition().x > 1400.f)
			reset();
}

void Beautify::load(const std::string& path, float y, float scale, float spd)
{
	if (!tex.loadFromFile(path))
		std::cerr << "Failed to load beauty image\n";
	sprite.setTexture(tex);
	sprite.setScale(scale, scale);
	sprite.setPosition(-500.f, y);
	speed = spd;
}


void Beautify::reset()
{
	
	sprite.setPosition(-500.f, sprite.getPosition().y);
}
//NEW VERSION
//void Beautify::reset()
//{
//	sprite.setPosition(-tex.getSize().x * sprite.getScale().x, sprite.getPosition().y);
//}

	//sprite.setPosition(-tex.getSize().x * sprite.getScale().x, sprite.getPosition().y);

float Beautify::getRightEdge() const 
{
	return sprite.getPosition().x + tex.getSize().x * sprite.getScale().x;
}

float Beautify::getX() const 
{
	return sprite.getPosition().x;
}