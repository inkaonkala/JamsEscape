/* * * * * * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * **
 * Author: Inka Niska												*
 * Email : inkaisinka@live.com										*
 *																	*
 *       (\(\  														*
 *      ( -.-)   Coding time...										*
 *     o_(")(") 													*
 *																	*
 *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * * * */

#ifndef OBS_HPP
#define OBS_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>


class Obstacle 
{
	public:
		virtual ~Obstacle() {}
		virtual void update(float gSpeed) = 0;
		virtual void draw(sf::RenderWindow& win) = 0;
		virtual sf::FloatRect getHitbox() const = 0;
};

//class Obs
//{
//	private:
//		sf::Texture		fence1;
//		sf::Sprite		fence;

//	public:
//		Obs();

//		void loadTex();

//		void draw(sf::RenderWindow& win);
//		void reset();
//} ;

#endif