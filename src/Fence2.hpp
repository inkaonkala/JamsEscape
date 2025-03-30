/* * * * * * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * **
 * Author: Inka Niska												*
 * Email : inkaisinka@live.com										*
 *																	*
 *       (\(\  														*
 *      ( -.-)   Coding time...										*
 *     o_(")(") 													*
 *																	*
 *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * * * */

#ifndef FENCE2_HPP
#define FENCE2_HPP

#include "Obs.hpp"

class Fence2 : public Obstacle
{
	private:
		sf::Sprite sprite;
		sf::Texture tex;

		float speed = 4.f;

	public:
		Fence2(float startX);
		void update(float gSpeed) override;
		void draw(sf::RenderWindow& win) override;
		sf::FloatRect getHitbox() const override;
};

#endif