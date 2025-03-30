/* * * * * * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * **
 * Author: Inka Niska												*
 * Email : inkaisinka@live.com										*
 *																	*
 *       (\(\  														*
 *      ( -.-)   Coding time...										*
 *     o_(")(") 													*
 *																	*
 *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * * * */

#include "gameBase.hpp"
#include "Piggy.hpp"
#include "Obs.hpp"
#include "Beautify.hpp"
#include "Ghost.hpp"

gameBase::gameBase()
{
	this->init_var();
	this->init_win();
}

gameBase::~gameBase()
{
	delete this->win;
}

const bool gameBase::whilstRunning() const
{
	return this->win->isOpen();
}

void gameBase::init_var()
{
	this->state = GameState::Menu;

	if (!this->font.loadFromFile("assets/font.otf"))
		std::cerr << "Failed to download the font\n";

	cloud.load("assets/cloud.png", 100.f, 0.8f, 0.5f);
	flower.load("assets/flower.png", 200.f, 1.7f, 10.f);	

	this->menuText.setFont(this->font);
	this->menuText.setCharacterSize(32);
	this->menuText.setFillColor(sf::Color::White);
	this->menuText.setString("Jam's escape");
	this->menuText.setPosition(100.f, 100.f);

	pointsTex.setFont(this->font);
	pointsTex.setCharacterSize(24);
	pointsTex.setFillColor(sf::Color::White);
	pointsTex.setPosition(20.f, 20.f);
	pointsTex.setString("Oinks: 0");

	this->piggy.loadTex();
	this->back.setupTheBack();

	if (!backGroundMusic.openFromFile("assets/JamsJam.wav"))
		std::cerr << "Error: Could not open the music file\n";
	else
		backGroundMusic.setLoop(true);

	ghostTimer.restart();
}

void gameBase::init_win()
{
	this->videoMode.width = 1400;
	this->videoMode.height = 600;
	this->win = new sf::RenderWindow(this->videoMode, "Jam's escape", sf::Style::Titlebar | sf::Style::Close);
	this->win->setFramerateLimit(60);
}

void gameBase::pollEvents()
{
	while (this->win->pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::Closed)
			this->win->close();
		if (this->ev.type == sf::Event::KeyPressed)
		{
			if (this->state == GameState::Menu)
			{
				if (ev.key.code == sf::Keyboard::Enter)
				{
					this->state = GameState::PlayingStart;
				}
			}
			if (this->state == GameState::GameOver)
			{
				if (ev.key.code == sf::Keyboard::Enter)
				{
					this->state = GameState::Menu;
					//reset pig
					//reset obsticles
				}
			}
		}
	}
}

void gameBase::update()
{
	pollEvents();

	switch (state)
	{
		case GameState::Menu:
			updateMenu();
			break;
		case GameState::PlayingStart:
			back.resetFarm();
			updateStart();
			break;
		case GameState::PlayingMove:
			if (!musicStarted)
			{
				backGroundMusic.play();
				musicStarted = true;
			}
			updateGameplay();
			break;
		case GameState::GameOver:
			// Could handle GameOver stuff here later
			break;
	}
}

void gameBase::checkCollisions()
{
	for (const auto& o : obs)
	{
		if (o->getHitbox().intersects(piggy.getHitBox()))
		{
			backGroundMusic.stop();
			musicStarted = false;
			state = GameState::PlayingStart;
			obs.clear();
			piggy.reset();
			back.resetFarm();
			showFlower = false;
			flowerTimer.restart();
			flower.reset();
			gameSpeed = 1.0f;
			deaths.push_back(
				{
					piggy.getPosition().y,
					ghostTimer.getElapsedTime(),
					false
				}
			);
			break;
		}
	}
}

void gameBase::spawnObstacle()
{

	if (obstacleClock.getElapsedTime().asSeconds() > spawnInterval)
	{
		for (auto& death : deaths)
		{
			if (!death.ghostSpawned && ghostTimer.getElapsedTime() - death.timeOfDeath > sf::seconds(10.f))
			{
				obs.push_back(std::make_unique<Ghost>(-100.f, death.y));
				death.ghostSpawned = true;
				obstacleClock.restart();
				return;
			}
		}
		int r = rand() % 100;
		if (r < 55)
			obs.push_back(std::make_unique<Fence>(0.f));
		else if (r < 85)
			obs.push_back(std::make_unique<Fence2>(0.f));
		else
			obs.push_back(std::make_unique<Cow>(0.f));

		obstacleClock.restart();
	}
}

void gameBase::render()
{
	this->win->clear();

	if (this->state == GameState::Menu)
	{
		this->win->draw(this->menuText);
	}
	if (this->state == GameState::PlayingStart || this->state == GameState::PlayingMove)
	{
		back.draw(*win);
		back.drawFarm(*win, state);
		piggy.draw(*win);
		cloud.draw(*win);
//		flower.draw(*win);
//		obs.draw(*win);
	}
	if (this->state == GameState::PlayingMove)
	{
	//	obs.push_back(std::make_unique<Fence>(0.f)); // off-screen start
		this->win->draw(pointsTex);
		for (auto& obs : obs)
			obs->draw(*win);
		// enemies start to loop
		cloud.draw(*win);
		flower.draw(*win);
	}
	this->win->display();
}


		