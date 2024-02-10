#include "Player.h"

void Player::InitVariables()
{


}

void Player::InitPlayer()
{
	if (this->texture.loadFromFile("resources/models/spaceship.png"))
	{
		this->spaceship.setTexture(this->texture);
		this->spaceship.scale(0.5f, 0.5f);
	}
	else
	{
		std::cout << "Error loading spaceship in player.cpp" << "\n";
	}

}

void Player::InitDamageSound()
{
	if (this->buffer.loadFromFile("resources/audio/damage.wav"))
	{
		std::cout << "Audio loaded sucessfully" << endl;
		this->sound.setBuffer(buffer);
		sound.setVolume(50);
	}
	else
	{
		cout << "Error loading audio::Player.cpp::damagesound" << "\n";
	}
}

Player::Player(float x, float y)
{
	this->InitPlayer();
	this->spaceship.setPosition(x, y);
	this->InitDamageSound();
}

Player::~Player()
{

}




void Player::updateInput()
{
	static Clock bulletCooldown;
	float bulletCooldownDuration = 0.2f;
	float speed = 4.f;
	float diagonalSpeed = sqrt((speed * speed) / 2);
	// Diagonal movement (top-left)
	if (Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::W))
	{
		this->spaceship.move(-diagonalSpeed, -diagonalSpeed);
	}
	// Diagonal movement (top-right)
	else if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::W))
	{
		this->spaceship.move(diagonalSpeed, -diagonalSpeed);
	}
	// Diagonal movement (bottom-right)
	else if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::S))
	{
		this->spaceship.move(diagonalSpeed, diagonalSpeed);
	}
	// Diagonal movement (bottom-left)
	else if (Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::S))
	{
		this->spaceship.move(-diagonalSpeed, diagonalSpeed);
	}
	// Regular movement (left)
	else if (Keyboard::isKeyPressed(Keyboard::A))
	{
		this->spaceship.move(-speed, 0.f);
	}
	// Regular movement (right)
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		this->spaceship.move(speed, 0.f);
	}
	// Regular movement (down)
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		this->spaceship.move(0.f, speed);
	}
	// Regular movement (up)
	else if (Keyboard::isKeyPressed(Keyboard::W))
	{
		this->spaceship.move(0.f, -speed);
	}
	

}


void Player::UpdateCollision(const RenderTarget& target)
{

	FloatRect playerPos = this->spaceship.getGlobalBounds();

	//left
	if (playerPos.left <= 6.f)
		this->spaceship.setPosition(6.f, playerPos.top);

	//right

	else if (playerPos.left + playerPos.width >= target.getSize().x)
	{
		this->spaceship.setPosition(1280 - playerPos.width, playerPos.top);

	}
	playerPos = this->spaceship.getGlobalBounds();
	//top
	if (playerPos.top <= 6.f)
		this->spaceship.setPosition(playerPos.left, 6.f);

	//bottom
	else if (playerPos.top + playerPos.height >= (target.getSize().y - 6.f))
	{

		this->spaceship.setPosition(playerPos.left, target.getSize().y - (playerPos.height + 6.f));
	}


}



void Player::PlayDamageSound()
{
	this->sound.play();
}

const Sprite& Player::getSpaceShipPos() const
{
	cout<<this->spaceship.getPosition().x<<endl;
	return this->spaceship;
}


void Player::update(const RenderTarget& target)
{
	
	this->updateInput();
	this->UpdateCollision(target);
	
}

void Player::render(RenderTarget& target)
{
	target.draw(this->spaceship);
}
