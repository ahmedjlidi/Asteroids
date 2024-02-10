#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include "Bullet.h"


using namespace std;
using namespace sf;

class Player
{
private:

		//inisializers
	void InitVariables();
	void InitPlayer();
	void InitDamageSound();


	//objects (of other classes)
	Bullet lazerbeam;
	

	//variables
	bool Shoot = false;


	
	//resources
	Texture texture;
	Sprite spaceship;

	SoundBuffer buffer;
	Sound sound;
	//functions
	
	

	


public:
	vector<int>n;
	//destrucvtos constructors
	Player(float x = 580 , float y = 500 );
	virtual ~Player();

	//variables

	//fucntions
	vector<int> test;
	vector<Sprite> GetBulletSprites;

	

	//(updaste and render window)
	void PlayDamageSound();
	const Sprite& getSpaceShipPos() const;
	void UpdateCollision(const RenderTarget& target);
	void updateInput();
	void update(const RenderTarget& target);
	void render(RenderTarget& target);



};

