/* * * * * * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * **
 * Author: Inka Niska												*
 * Email : inkaisinka@live.com										*
 *																	*
 *       (\(\  														*
 *      ( -.-)   Coding time...										*
 *     o_(")(") 													*
 *																	*
 *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * * * */

#ifndef PIGGY_HPP
#define PIGGY_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

enum class JumpPhase
{
	Grounded,
	JumpingUp,
	Fallin,
	TimeStopped,
	DropAfterTimeStop
};

class Piggy
{
	private:
		JumpPhase	jumpPhase;
		
		sf::Texture					pigTex1, pigTex2;
		std::vector<sf::Sprite>		Jams;
		sf::Sprite					Jam;
		sf::Vector2f 				velocity;

		sf::Texture					pigTex3;
		sf::Sprite					flatJam;

		int							points = 0;

		// for Jam animation and move
		float						speed;
		int currentFrame = 0;
		sf::Clock animationClock;
		
		bool	tex0 = true;
		float animationDelay = 0.2f;
		bool isAnimating = false;

		sf::Clock jumpClock;
		sf::Clock landClock;

		bool isFlat = false;
		float flatTimer = 0.2f;

		// for theJump
		float yVelocity = 0.f;
		float gravity = 0.5f;
		bool spaceHit = false;
		sf::Clock holdClock;

	public:
		Piggy();

//		void loadTex(const std::string& path);
		void loadTex();
		void animateJam();
		void reset();
		void start();
		void draw(sf::RenderWindow& win);

		void moveLeft();
		void jump();
		void updateMoveMode(bool timeStopped);
		bool isTimeFrozen() const;
		int getPoints() const;
		
		// HIT BOX!
		sf::FloatRect getHitBox() const;
		sf::Vector2f getPosition() const;
};

#endif