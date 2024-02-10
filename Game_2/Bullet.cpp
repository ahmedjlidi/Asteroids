#include "Bullet.h"

void Bullet::InitTexture()
{
	if (this->texture.loadFromFile("resources/models/bullet.png"))
	{
		this->BulletShape.setTexture(this->texture);
		this->BulletShape.scale(0.1f, 0.1f);
	}
	else
	{
		std::cout << "Error loading spaceship in player.cpp" << "\n";
	}

}
void Bullet::InitSound()
{
	if (this->buffer.loadFromFile("resources/audio/lazerbeam.wav"))
	{
		std::cout << "Loading assets" << endl;
		this->sound.setBuffer(buffer);
		sound.setVolume(50);
	}
	else
	{
		cout << "Error loading audio::bullet.cpp::lazerbeamSound" << "\n";
	}
}



void Bullet::InitBullet()
{
	this->speed = 5.f;
}





Bullet::Bullet()
{
	this->InitBullet();
	this->InitTexture();
	this->InitSound();
}



Bullet::~Bullet()
{

}






vector<sf::Sprite>& Bullet::getBullets() 
{
	return this->Bullets;
}

void Bullet::spawn(Vector2f xy)
{
	this->BulletShape.setPosition(xy);
	this->sound.play();
	this->Bullets.push_back(BulletShape);
}



void Bullet::update()
{
	
	for (auto i = 0; i < this->Bullets.size(); i++)
	{
		this->Bullets[i].move(0.f, -this->speed);
		
	}
	for (auto it = this->Bullets.begin(); it != this->Bullets.end();) 
	{
		if (it->getPosition().y <= 0) {
			it = this->Bullets.erase(it);
		}
		else {
			it->move(0.f, -this->speed);
			++it;
		}
	}

}


void Bullet::render(RenderTarget& target)
{
	for (auto& e : this->Bullets)
	{
		target.draw(e);
	}
}

