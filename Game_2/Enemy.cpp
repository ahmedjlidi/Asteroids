#include "Enemy.h"

void Enemy::InitTexture()
{
	if (this->texture.loadFromFile("resources/models/asteroid.png"))
	{
		this->asteroid.setTexture(this->texture);
		this->asteroid.scale(0.175f, 0.175f);

	}
	else
	{
		std::cout << "Error loading spaceship in player.cpp" << "\n";
	}

}

void Enemy::InitVariables()
{
	this->MaxAsteroids = 20;
	this->SpawnTimerMax = 1000.f;
	this->SpawnTimer = this->SpawnTimerMax;
}

Enemy::Enemy()
{

	this->InitTexture();
	this->InitVariables();
}

Enemy::~Enemy()
{

}



void Enemy::spawn()
{
	try {
		//setting radom spawn position for balls
		this->asteroid.setPosition(
			static_cast<float>(rand() % static_cast<int> (1200 - 30)),
			0.f);

		bool overlap = false;
		for (const auto& existingEnemy : this->asteroids)
		{


			if (this->asteroid.getGlobalBounds().intersects(existingEnemy.getGlobalBounds())) {
				overlap = true;
				break; // Making sure enmies dont spawn on top of each other
			}

		}
		if (!overlap)
		{

			//if balls dont spawn on top of each other set their raduis and color  randomly and push them to vector
			this->asteroids.push_back(this->asteroid);

		}
	}



	catch (const std::exception& e) {
		// Handle the exception (print an error message, log, etc.)
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

}
vector<sf::Sprite>& Enemy::getAsteroids() 
{
	return this->asteroids;
}

void Enemy::removeAsteroid(size_t index)
{
	this->asteroids.erase(asteroids.begin() + index);
}


void Enemy::updateSpawn(const RenderTarget& target)
{
	// Delay between spawns (in seconds)

	float spawnDelay = 0.5f; // Adjust this value as needed

	// Start the delay timer
	static Clock delayTimer;
	float elapsedDelayTime = delayTimer.getElapsedTime().asSeconds();

	// Spawn asteroids based on a timer
	while (elapsedDelayTime >= spawnDelay && this->asteroids.size() <= this->MaxAsteroids)
	{
		if (this->SpawnTimer >= this->SpawnTimerMax)
		{
			// Spawn asteroid and reset timer
			this->spawn();
			delayTimer.restart();
			this->SpawnTimer = 0.f;
		}
		else
		{
			this->SpawnTimer += 0.1f;
		}
		elapsedDelayTime = delayTimer.getElapsedTime().asSeconds(); // Update elapsed time
	}



	//erase asteroid if it is outside the window
	for (auto it = this->asteroids.begin(); it != this->asteroids.end();)
	{
		if (it->getPosition().y > 720)
		{
			it = this->asteroids.erase(it);

		}
		//else if (it->getPosition().x >= this->window->getSize().x)
		   // this->enemies[i].move(this->RandomX[i] * -1, 3.5f);

		else
			++it;
	}


	//iterate thropught bullets vector and erase member if it collides with player 
	// Move existing asteroids
	for (auto& asteroid : this->asteroids)
	{
		asteroid.move(0.f, this->speed);
	}
}




void Enemy::update(const RenderTarget& target)
{

	this->updateSpawn(target);
}



void Enemy::render(RenderTarget& target)
{
	for (auto& e : this->asteroids)
	{
		target.draw(e);
	}
}

