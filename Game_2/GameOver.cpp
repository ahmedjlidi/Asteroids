#include "GameOver.h"


void GameOver::InitText()
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

void GameOver::InitButton()
{
	this->Continue.setFont(this->font);
	this->Continue.setCharacterSize(60);
	this->Continue.setFillColor(Color(39, 246, 19));
	this->Continue.setPosition(575, 375);
	this->Continue.setString("Exit");


	button.setSize(Vector2f(260, 70));
	button.setFillColor(Color::Transparent);
	button.setOutlineColor(Color::Transparent);
	button.setOutlineThickness(3);
	button.setPosition(515, 375);

}

void GameOver::InitScore()
{
	this->Score.setFont(this->font);
	this->Score.setCharacterSize(90);
	this->Score.setFillColor(Color(218, 213, 33));
	this->Score.setPosition(430, 160);

}


void GameOver::SetScore(int& score)
{
	
	std::stringstream iss;
	iss << "Score: " << score << std::endl;
	this->Score.setString(iss.str());
}

GameOver::GameOver()
{
	this->InitScore();
	//int score;
	//this->SetScore(score);

	this->InitText();
	this->InitButton();
}

bool GameOver::ExitGame(const RenderWindow& target)
{
	static bool wasPressed = false;
	static bool isClicked = false;
	static int MousePress = 0;

	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (!wasPressed)
		{
			isClicked = true;
			MousePress++;

			wasPressed = true;
		}
		else
		{
			isClicked = false;
		}
	}
	else
	{
		wasPressed = false;
		isClicked = false;
	}

	return (isClicked && MousePress > 1 && this->button.getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition(target))));
}




void GameOver::Idle()
{
	this->Continue.setFillColor(Color(39, 246, 19));
}

bool GameOver::hover(const RenderWindow& target)
{
	return (this->button.getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition(target))));
}

void GameOver::setHoverColor()
{

	this->Continue.setFillColor(Color(29, 117, 21));

}



void GameOver::update(const RenderWindow& target)
{
	this->ExitGame(target);
	this->hover(target);
	this->setHoverColor();
}


void GameOver::render(RenderWindow& target)
{
	target.draw(this->button);
	target.draw(this->Score);
	target.draw(this->Continue);
}




