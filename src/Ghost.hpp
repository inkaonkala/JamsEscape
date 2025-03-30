/* * * * * * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * **
 * Author: Inka Niska												*
 * Email : inkaisinka@live.com										*
 *																	*
 *       (\(\  														*
 *      ( -.-)   Coding time...										*
 *     o_(")(") 													*
 *																	*
 *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * * * */

#ifndef GHOST_HPP
#define GHOST_HPP

#include "Obs.hpp"

class Ghost : public Obstacle
{
	private:
		sf::Sprite sprite;
		sf::Texture tex1, tex2;

		sf::Clock animationClock;

		float animationDelay = 0.3f;
		bool atFirstFrame = true;

		float speed = 3.5f;
		float floatRange = 30.f;
//		float floatSpeed = 0.05f;
		float startY;

	public:
		Ghost(float startX, float startY);
		void update(float gSpeed) override;
		void draw(sf::RenderWindow& win) override;
		sf::FloatRect getHitbox() const override;
};

#endif