/* * * * * * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * **
 * Author: Inka Niska												*
 * Email : inkaisinka@live.com										*
 *																	*
 *       (\(\  														*
 *      ( -.-)   Coding time...										*
 *     o_(")(") 													*
 *																	*
 *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * * * */

#ifndef BACKROUND_HPP
#define BACKROUND_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
//#include "gameBase.hpp"

enum class GameState;

class Backround
{
	private:
		sf::Texture	br, startBr, farmTex;
		sf::Sprite	back1, back2, back3, farm;

		bool farmSliding = false;
//		float scrollSpeed = 0.3f;

	public:
		Backround() {};

		void setupTheBack();
		void draw(sf::RenderWindow& win);
		void triggerFarmSlide();
		void updateFarm();
		void drawFarm(sf::RenderWindow& win, GameState state);
		void resetFarm();
};

#endif