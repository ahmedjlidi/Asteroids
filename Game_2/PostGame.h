#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace sf;


class PostGame
{
private:

	void InitText();
	void InitButton();
	void IinitYouLost();

	Font font;
	Text YouLost;
	Text Continue;

	RectangleShape button;

public:
	PostGame();
	

	bool ExitToGameOverScreem(const RenderWindow & target);
	void Idle();
	bool hover(const RenderWindow& target);
	void setHoverColor();

	void update(const RenderWindow& target);
	void render(RenderWindow& target);


};

