/* * * * * * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * **
 * Author: Inka Niska												*
 * Email : inkaisinka@live.com										*
 *																	*
 *       (\(\  														*
 *      ( -.-)   Coding time...										*
 *     o_(")(") 													*
 *																	*
 *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * * * */

#ifndef COW_HPP
#define COW_HPP

#include "Obs.hpp"

class Cow: public Obstacle
{
	private:
		sf::Sprite sprite;
		sf::Texture tex1, tex2;

		float speed = 4.f;

		sf::Clock animationClock;
		float animationDelay = 0.4f;
		bool useTex1 = true;

	public:
		Cow(float startX);
		void update(float gSpeed) override;
		void draw(sf::RenderWindow& win) override;
		sf::FloatRect getHitbox() const override;
};

#endif