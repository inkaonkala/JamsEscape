/* * * * * * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * **
 * Author: Inka Niska												*
 * Email : inkaisinka@live.com										*
 *																	*
 *       (\(\  														*
 *      ( -.-)   Coding time...										*
 *     o_(")(") 													*
 *																	*
 *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * * * */

#ifndef GAMEBASE_HPP
#define GAMEBASE_HPP

#include <iostream>
#include <vector>
#include <ctime>
#include <memory>

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

#include "Piggy.hpp"
#include "Obs.hpp"
#include "backround.hpp"
#include "Fence.hpp"
#include "Fence2.hpp"
#include "Cow.hpp"
#include "Beautify.hpp"

enum class GameState
{
	Menu,
	PlayingStart,
	PlayingMove,
	GameOver
};

struct DeathData
{
	float 			y;
	sf::Time		timeOfDeath;
	bool			ghostSpawned = false;
};

class gameBase
{
	private:
		GameState	state;
		Piggy		piggy;
		Backround	back;
		Beautify	cloud;
		Beautify	flower;
		

		sf::RenderWindow	*win;
		sf::Event			ev;
		sf::VideoMode		videoMode;

		sf::Font			font;
		sf::Text			menuText;
		sf::Text			pointsTex;

		sf::Clock			speedUpTimer;		
		sf::Clock			obstacleClock;
		sf::Clock 			flowerTimer;

		float				gameSpeed = 1.0f;
		float				spawnInterval = 3.1f;
		bool				showFlower = false;
		std::vector<std::unique_ptr<Obstacle>> obs;

		std::vector<DeathData> deaths;
		sf::Clock			ghostTimer;

		sf::Music			backGroundMusic;
		bool				musicStarted = false;
		
	public:

		gameBase();
		virtual ~gameBase();

		const bool whilstRunning() const;
		void pollEvents();
		void update();
		void render();
		void init_var();
		void init_win();
		void updateGameplay();
		void updateMenu();
		void updateStart();
		void checkCollisions();
		void spawnObstacle();
		void updateBeauty();
};

#endif