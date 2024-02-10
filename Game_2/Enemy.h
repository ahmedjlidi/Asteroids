#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <ctime>
#include <vector>


using namespace sf;
using namespace std;




class Enemy
{
	//inisializers

	
	


	//variables
	float speed = 2.f;
	float SpawnTimerMax;
	float SpawnTimer;
	int MaxAsteroids;



	//resources
	Texture texture;
	Sprite asteroid;
	vector<Sprite>asteroids;


	//functions
	void InitTexture();
	void InitVariables();





public:

	//destrucvtos constructors
	Enemy();
	virtual ~Enemy();

	//variables

	//fucntions
	void spawn();
	vector<sf::Sprite>& getAsteroids();
	void removeAsteroid(size_t index);
	void updateSpawn(const RenderTarget& target);
	void update(const RenderTarget& target);
	void render(RenderTarget& target);

};

