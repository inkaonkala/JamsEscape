/* * * * * * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * **
 * Author: Inka Niska												*
 * Email : inkaisinka@live.com										*
 *																	*
 *       (\(\  														*
 *      ( -.-)   Coding time...										*
 *     o_(")(") 													*
 *																	*
 *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * *  * * * * * */

#include "Piggy.hpp"

Piggy::Piggy()
{
	speed = 2.5f;
	jumpPhase = JumpPhase::Grounded;
	gravity = 0.5f;
	yVelocity = 0.f;
	reset();
}

//void Piggy::loadTex(const std::string& path)
void Piggy::loadTex()
{
	Jams.clear();

	if (!pigTex1.loadFromFile("assets/pig1.png"))
		std::cerr << "Error loading piggy1 image\n";
	if (!pigTex2.loadFromFile("assets/pig2.png"))
		std::cerr << "Error loading piggy2 image\n";
	if (!pigTex3.loadFromFile("assets/pig3.png"))
		std::cerr << "Error loading piggy3\n";

	sf::Sprite frame1(pigTex1);
	sf::Sprite frame2(pigTex2);
	sf::Sprite flatJam(pigTex3);

	frame1.setOrigin(pigTex1.getSize().x / 2.f, pigTex1.getSize().y / 2.f);
	frame2.setOrigin(pigTex2.getSize().x / 2.f, pigTex2.getSize().y / 2.f);
	flatJam.setOrigin(pigTex3.getSize().x / 2.f, pigTex3.getSize().y / 2.f);
//	Jam.setTexture(pigTex1);
	frame1.setScale(0.3f, 0.3f);
	frame2.setScale(0.3f, 0.3f);
	flatJam.setScale(0.3f, 0.3f);

	Jams.push_back(frame1);
	Jams.push_back(frame2);

	Jam = Jams[0];

	flatJam.setTexture(pigTex3); // ← ADD THIS
	flatJam.setOrigin(pigTex3.getSize().x / 2.f, pigTex3.getSize().y / 2.f);
	flatJam.setScale(0.3f, 0.3f);
	flatJam.setPosition(1100.f, 530.f);

	this->flatJam = flatJam;
//	Jam.setOrigin(pigTex1.getSize().x / 10.f, pigTex1.getSize().y / 10.f);
	Jam.setPosition(1100.f, 500.f);
}

void Piggy::reset()
{
	Jam.setPosition(1100.f, 500.f);
	yVelocity = 0.f;
	jumpPhase = JumpPhase::Grounded;
	holdClock.restart();
	isFlat = false;
	points = 0;
}

void  Piggy::draw(sf::RenderWindow& win)
{
	if (isFlat)
		win.draw(flatJam);
	else
		win.draw(Jam);
}

void Piggy::updateMoveMode(bool timeStopped)
{
	if (isFlat)
	{
		if (landClock.getElapsedTime().asSeconds() > flatTimer)
		{
			isFlat = false;
		}
		return;
	}
	isAnimating = !timeStopped;
	animateJam();
	jump();
}

void Piggy::moveLeft()
{
    if (Jam.getPosition().x > 0)
	{
        Jam.move(-speed, 0.f);	
				if (tex0)
		{
			Jam.setTexture(*Jams[1].getTexture());
			tex0 = false;
		}
		else
		{
			Jam.setTexture(*Jams[0].getTexture());
			tex0 = true;
		}
	}
}

void Piggy::jump()
{
	switch (jumpPhase)
	{
		case JumpPhase::Grounded:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				yVelocity = -12.f;
				jumpPhase = JumpPhase::JumpingUp;
				spaceHit = false;
			}
			break;

		case JumpPhase::JumpingUp:
			//hight checker
			if (Jam.getPosition().y + yVelocity < 0.f)
			{
				Jam.setPosition(Jam.getPosition().x, 0.f);
				yVelocity = 0.f;
				break;
			}
			spaceHit = false;
			yVelocity += gravity;
			Jam.move(0.f, yVelocity);
			if (yVelocity >= 0)
			{
				jumpPhase = JumpPhase::Fallin;
			}
			break;

		case JumpPhase::Fallin:
			yVelocity += gravity;
			Jam.move(0.f, yVelocity);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !spaceHit)
			{
				holdClock.restart();
				jumpPhase = JumpPhase::TimeStopped;
				spaceHit = true;
			}
			else if (Jam.getPosition().y >= 500.f)
			{
				Jam.setPosition(Jam.getPosition().x, 500.f);
				yVelocity = 0.f;
				jumpPhase = JumpPhase::Grounded;
				points++;
				spaceHit = false;
				isFlat = true;
				flatJam.setPosition(Jam.getPosition());
				landClock.restart();
			}
			break;

		case JumpPhase::TimeStopped:
			
			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				yVelocity = 0.f;
				jumpPhase = JumpPhase::DropAfterTimeStop;
			}
			break;

		case JumpPhase::DropAfterTimeStop:
			yVelocity += gravity;
			Jam.move(0.f, yVelocity);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !spaceHit)
			{
				holdClock.restart();
				jumpPhase = JumpPhase::TimeStopped;
				spaceHit = true;
			}
			else if (Jam.getPosition().y >= 500.f)
			{
				Jam.setPosition(Jam.getPosition().x, 500.f);
				yVelocity = -holdClock.getElapsedTime().asSeconds() * 15.f;
				jumpPhase = JumpPhase::JumpingUp;
			}
			break;
	}
}

void	Piggy::start()
{
	spaceHit = false;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		moveLeft();
}

void Piggy::animateJam()
{
		if (animationClock.getElapsedTime().asSeconds() > animationDelay)
		{
			currentFrame = (currentFrame + 1) % Jams.size();
			Jam.setTexture(*Jams[currentFrame].getTexture());
			animationClock.restart();
		}
}

sf::FloatRect Piggy::getHitBox() const
{
	return Jam.getGlobalBounds();
}

sf::Vector2f Piggy::getPosition() const
{
	return Jam.getPosition();
}

bool Piggy::isTimeFrozen() const
{
	return jumpPhase == JumpPhase::TimeStopped;
}

int Piggy::getPoints() const
{
	return points;
}