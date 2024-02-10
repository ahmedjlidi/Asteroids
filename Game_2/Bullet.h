#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;


class Bullet
{

private:

	//inisializers
	void InitBullet();
	void InitSound();

	//objects (of other classes)



	//variables
	float speed;
	float x;
	float y;
	float pos_x; float pos_y;
	float movement_speed;





	//resources
	Sprite BulletShape;
	Texture texture;
	vector<Sprite>Bullets;

	SoundBuffer buffer;
	Sound sound;

	//functions
	void InitTexture();


public:

	//destrucvtos constructors
	Bullet();
	virtual ~Bullet();
	//variables
	//fucntions
	vector<sf::Sprite>& getBullets();
	void spawn(Vector2f xy);
	void update();
	void render(RenderTarget& target);


};


