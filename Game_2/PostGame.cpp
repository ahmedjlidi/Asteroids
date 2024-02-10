#include "PostGame.h"

void PostGame::InitText()
{
	if (this->font.loadFromFile("resources/Fonts/PixelifySans-Regular.ttf"))
	{
		std::cout << "Loading assets" << std::endl;
	}
	else
	{
		std::cout << "Error loading Fonts" << std::endl;
	}

}

void PostGame::IinitYouLost()
{
	this->YouLost.setFont(this->font);
	this->YouLost.setCharacterSize(120);
	this->YouLost.setFillColor(Color(218, 213, 33));
	this->YouLost.setPosition(400, 200);
	this->YouLost.setString("You Lost");

}


void PostGame::InitButton()
{

	this->Continue.setFont(this->font);
	this->Continue.setCharacterSize(60);
	this->Continue.setFillColor(Color(39, 246, 19));
	this->Continue.setPosition(515, 375);
	this->Continue.setString("Continue");


	button.setSize(Vector2f(260,70));
	button.setFillColor(Color::Transparent);
	button.setOutlineColor(Color::Transparent);
	button.setOutlineThickness(3);
	button.setPosition(515, 375);

}

PostGame::PostGame()
{
	this->InitText();
	this->InitButton();
	this->IinitYouLost();
}

bool PostGame::ExitToGameOverScreem(const RenderWindow& target)
{
		return (this->button.getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition(target)))
			&& Mouse::isButtonPressed(Mouse::Left));
}


void PostGame::Idle()
{
	this->Continue.setFillColor(Color(39, 246, 19));
}

bool PostGame::hover(const RenderWindow& target)
{
	return (this->button.getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition(target))));
}

void PostGame::setHoverColor()
{

	this->Continue.setFillColor(Color(29, 117, 21));

}



void PostGame::update(const RenderWindow &target)
{
	this->ExitToGameOverScreem(target);
	this->hover(target);
	this->setHoverColor();
}

void PostGame::render(RenderWindow &target)
{
	
	target.draw(this->button);
	target.draw(this->YouLost);
	target.draw(this->Continue);
}
