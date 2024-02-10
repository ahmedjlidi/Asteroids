#include "Game.h"


void Game::InitWindow()
{
	this->videomode.height = 1280;
	this->videomode.width = 720;
	this->window = new RenderWindow(VideoMode(this->videomode.height, this->videomode.width), "Game", Style::Resize | Style::Close);
	this->window->setFramerateLimit(240);
}



void Game::InitBackground()
{
	if (this->texture.loadFromFile("resources/models/background.png"))
	{
		this->Background.setTexture(this->texture);
		this->Background.scale(0.5f, 0.5f);
	}
	else
	{
		std::cout << "Error loading textures in player.cpp" << "\n";
	}
}

void Game::InitHpBar()
{
	float x = 20;
	float y = 20;
	this->height = 200.f;
	this->width = 50.f;
	this->HpBar.setSize(Vector2f(this->height, this->width));
	this->HpBar.setFillColor(Color::Red);
	this->HpBar.setOutlineColor(Color::Black);
	this->HpBar.setOutlineThickness(3.f);
	this->HpBar.setPosition(x, y);
	this->Hp = 100;

}

void Game::InitFont()
{
	if (this->font.loadFromFile("resources/Fonts/PixelifySans-Regular.ttf"))
	{
		
		this->HpScore.setFont(this->font);
		this->HpScore.setCharacterSize(40);
		this->HpScore.setFillColor(Color::Green);
		this->HpScore.setPosition(250, 20);
		


		this->score.setFont(this->font);
		this->score.setCharacterSize(40);
		this->score.setFillColor(Color::Green);
		this->score.setPosition(1060, 20);
		
	}
	else
	{
		cout << "Error loading Fonts" << endl;
	}
}

void Game::PLayMenuSound()
{
	if (!Exitmenu)
		this->mainmenu.PlaySound();
	
}

Game::Game()
{
	this->PLayMenuSound();
	this->InitWindow();
	this->InitBackground();
	this->InitHpBar();
	this->InitFont();
}

Game::~Game()
{
	delete this->window;

}


void Game::PollEvent()
{
	

	// Other event handling goes here
	
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case Event::Closed:
			this->window->close();
			break;

			// Other event handling goes here

		}
		
	}
}

void Game::ShootBullet()
{
	float spawnDelay = 0.175f; // Adjust this value as needed
	bool shooting = false;
	bool AllowShooting = false;
	static Clock delayTimer;
	static Clock DelayBeforeStart;

	// Check if Exitmenu is true to start DelayBeforeStart
	if (Exitmenu == true)
	{
		Time elapsed = DelayBeforeStart.getElapsedTime();

		// Check if elapsed time is greater than 2 seconds before allowing shooting
		if (elapsed.asSeconds() >= 0.75f)
		{
			AllowShooting = true;
		}

		// Perform shooting action if conditions are met
		if (Mouse::isButtonPressed(Mouse::Left) && delayTimer.getElapsedTime().asSeconds() > spawnDelay && AllowShooting)
		{
			this->bullet.spawn(this->player.getSpaceShipPos().getPosition());
			delayTimer.restart();
		}
	}
	else
	{
		// Reset all shooting-related states or timers if Exitmenu is not true
		delayTimer.restart();
		DelayBeforeStart.restart();
		AllowShooting = false;
	}

}


bool Game::EndGame()
{
	return this->Hp<10 ? true : false;
}

const bool Game::IsRunning()
{
	return this->window->isOpen();
}

void Game::UpdateScore()
{
	stringstream iss;
	iss << "Score: " << this->Score << endl;
	this->score.setString(iss.str());
}




void Game::UpdateHp()
{
	
	bool hit = false; // Track if a collision occurred
	
	for (size_t i = 0; i < this->enemy.getAsteroids().size(); i++)
	{
		// If player collides with asteroid
		if (this->player.getSpaceShipPos().getGlobalBounds().intersects(this->enemy.getAsteroids()[i].getGlobalBounds()))
		{
			
			hit = true; // Collision detected
			this->enemy.getAsteroids().erase(this->enemy.getAsteroids().begin() + i);
			break;
		}
	}

	if (hit)
	{
		if (!this->hpDeduct) // Check if deduction  occurr
		{
			this->player.PlayDamageSound();
			this->Hp -= 10; // reduce HP only once	
			this->UpdateHpbar();
			this->hpDeduct = true; // set bool to false
		}
	}
	else
	{
		this->hpDeduct = false; // Reset the bool if no collision detected
	}

	//cout << Hp << endl;
}

void Game::UpdateHPScore()
{
	stringstream iss;
	iss << "Hp: " << this->Hp<< endl;
	this->HpScore.setString(iss.str());
}

void Game::renderTextOnscreen()
{
	this->window->draw(this->score);
	this->window->draw(this->HpScore);
}





void Game::UpdateHpbar()
{
	this->height -= 20;
	cout << this->height << endl;
	this->HpBar.setSize(Vector2f(this->height, this->width));
}

void Game::CheckCollisionBetweenAsteroidAndBullet()
{
	const std::vector<sf::Sprite>& asteroids = enemy.getAsteroids();
	std::vector<sf::Sprite>& bullets = bullet.getBullets();

	for (size_t i = 0; i < asteroids.size(); ++i) {
    for (size_t j = 0; j < bullets.size(); ++j) {
        // Check if the bounding boxes of asteroid and bulletSprite intersect
        if (asteroids[i].getGlobalBounds().intersects(bullets[j].getGlobalBounds())) {
            // Remove the asteroid and bullet that collided
			this->Score += 5;
            enemy.removeAsteroid(i);
            bullets.erase(bullets.begin() + j);

            --i; // Adjust the index as the vector size has changed after removal
            break; // Exit the inner loop since asteroid is deleted
        }
    }
}

}

void Game::update()
{
	
	if (!EndGame())
	{
		if (Exitmenu)
		{
			this->mainmenu.StopSound();
			this->ShootBullet();
			this->bullet.update();
			this->CheckCollisionBetweenAsteroidAndBullet();
			this->player.update(*this->window);
			this->enemy.update(*this->window);
			this->UpdateHp();
			this->EndGame();
			this->UpdateScore();
			this->UpdateHPScore();
		}
		else
		{
			
			if (this->mainmenu.ExitMainmenu(*this->window))
				this->Exitmenu = true;
			else if (mainmenu.hover(*this->window))
				this->mainmenu.setHoverColor();
			else
				this->mainmenu.Idle();
			if (this->mainmenu.ExitGameFunction(*this->window))
				this->window->close();
			else if (this->mainmenu.hover1(*this->window))
				this->mainmenu.setHover1Color();
			else
				this->mainmenu.Idle1();
			
		}
	}
	else if (!GoToGameOverScreen) 
	{
		if (this->postgame.ExitToGameOverScreem(*this->window))
			this->GoToGameOverScreen = true;
		else if (postgame.hover(*this->window))
			this->postgame.setHoverColor();
		else
			this->postgame.Idle();
	}
	else 
	{
		this->gameover.SetScore(this->Score);
		if (this->gameover.ExitGame(*this->window))
		{
			this->window->close();
			
		}
		else if (gameover.hover(*this->window))
			this->gameover.setHoverColor();
		else
			this->gameover.Idle();
	}
}



void Game::render() 
{
	this->window->clear();
	this->window->draw(Background);

	if (!EndGame()) 
	{
		if (Exitmenu) 
		{
			// Rendering game elements when the game is ongoing and not in the exit menu
			this->enemy.render(*this->window);
			this->bullet.render(*this->window);
			this->player.render(*this->window);
			this->window->draw(HpBar);
			this->renderTextOnscreen();
		}
		else 
		{
			// Rendering the main menu when not in the exit menu
			
			
			this->mainmenu.render(this->window);
		}
	}
	else 
	{
		// Check if GoToGameOverScreen is true to render gameover or postgame screen
		if (!GoToGameOverScreen) 
		{
			
			this->postgame.render(*this->window);
		}
		else 
		{
			this->gameover.render(*this->window);

		}
	}

	this->window->display();
}


