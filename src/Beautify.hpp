/* * * * * * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * **
 * Author: Inka Niska												*
 * Email : inkaisinka@live.com										*
 *																	*
 *       (\(\  														*
 *      ( -.-)   Coding time...										*
 *     o_(")(") 													*
 *																	*
 *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * * * */

#ifndef BEAUTIFY_HPP
#define BEAUTIFY_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>


class Beautify
{
	protected:
		sf::Sprite	sprite;
		sf::Texture	tex;
		float 		speed;



	public:
		Beautify() = default;
		Beautify(const std::string& path, float y, float scale, float spd);
		virtual void update(float gSpeed);
		void load(const std::string& path, float y, float scale, float spd);
		virtual void draw(sf::RenderWindow& win) { win.draw(sprite); }
		virtual void reset();

		float getRightEdge() const; 
		float getX() const; 
};

#endif
