#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <sstream>
#include <fstream>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "MainMenu.h"
#include "PostGame.h"
#include "GameOver.h"


using namespace std;
using namespace sf;



class Game
{
private:


	//inisializers
	void InitWindow();
	void InitBackground();
	void InitHpBar();
	void InitFont();
	

	//objects (of other classes)
	Player player;
	Bullet bullet;
	Enemy enemy;
	MainMenu mainmenu;
	PostGame postgame;
	GameOver gameover;

	bool Exitmenu = false;
	bool GoToGameOverScreen = false;


	//variables
	vector<sf::Sprite> BulletPositions;
	int Hp;
	int Score = 0;
	bool hpDeduct = false;
	float height ;
	float width ;

	RectangleShape HpBar;

	SoundBuffer buffer;

	/*window variables*/
	RenderWindow* window;
	VideoMode videomode;
	Event ev;




	//resources
	Texture texture;
	Sprite Background;

	Text score;
	Text HpScore;
	Font font;


	//functions



public:

	//destrucvtos constructors
	Game();
	virtual ~Game();

	//variables
	void PLayMenuSound();
	//fucntions
	void UpdateHpbar();
	void PollEvent();
	bool EndGame();
	void ShootBullet();
	//(updaste and render window)
	void UpdateHp();
	void UpdateScore();
	void UpdateHPScore();
	void CheckCollisionBetweenAsteroidAndBullet();
	void update();
	void renderTextOnscreen();
	void render();

	void renderPostGame();
	
	

	const bool IsRunning();





};



