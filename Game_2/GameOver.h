#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <sstream>

using namespace sf;




class GameOver
{

private:

	void InitText();
	void InitButton();
	

	Font font;
	Text Score;
	Text Continue;

	RectangleShape button;

public:
	GameOver();


	bool ExitGame(const RenderWindow& target);
	void Idle();
	bool hover(const RenderWindow& target);
	void setHoverColor();
	void SetScore(int& score);
	void InitScore();

	void update(const RenderWindow& target);
	void render(RenderWindow& target);
};

