#include "MainMenu.h"



void MainMenu::InitFonts()
{
	//loading textures and passing them to a sprite object
	if (this->font.loadFromFile("resources/Fonts/PixelifySans-Regular.ttf"))
	{
		cout << "Loading assets" << endl;
	}
	else
	{
		cout << "Error loading Fonts" << endl;
	}


	
}

void MainMenu::InitSound()
{
	if (this->buffer.loadFromFile("resources/audio/menutheme.wav"))
	{
		std::cout << "Audio loaded (menutheme) sucessfully" << endl;
		this->sounds.setBuffer(buffer);
	}
	else
	{
		cout << "Error loading audio::menutheme.cpp::lazerbeamSound" << "\n";
	}
}


void MainMenu::GameName()
{

	if (this->FontType.loadFromFile("resources/Fonts/VinaSans-Regular.ttf"))
	{
		cout << "Font loaded successfully" << endl;
		this->Gamename.setFont(this->FontType);
		this->Gamename.setCharacterSize(100);
		this->Gamename.setFillColor(Color(218, 213, 33));
		this->Gamename.setPosition(380, 200);

		(this->Gamename.setString("SPACE INVADERS"));
	}
	else
	{
		cout << "Error loading Fonts" << endl;
	}
}

void MainMenu::InitBackground()
{
	if (this->texture.loadFromFile("resources/models/menuback.png"))
	{
		this->Background.setTexture(this->texture);
		this->Background.scale(0.3548f, 0.288f);
	}
	else
	{
		std::cout << "Error loading spaceship in player.cpp" << "\n";
	}

}
void MainMenu::InitButton(float ButtonposX, float ButtonposY,float pos_x,float pos_y, Color color,Color outline,Color fontColor,int outlineThick, Text &buttonText,
						RectangleShape &button,Vector2f ButtonSize,string text,int fontSize,Font &font)
{
	

	button.setSize(ButtonSize);
	button.setFillColor(color);
	button.setOutlineColor(outline);
	button.setOutlineThickness(outlineThick);
	button.setPosition(ButtonposX, ButtonposY);


	buttonText.setFont(font);
	buttonText.setCharacterSize(fontSize);
	buttonText.setFillColor(fontColor);
	buttonText.setPosition(pos_x,pos_y);

	(buttonText.setString(text));
	
}



void MainMenu::InitButtonStart()
{
	
	this->InitButton(515, 375, 550, 390, Color::Transparent, Color::Transparent, Color(39, 246, 19), 3, this->buttonText, this->button,
		Vector2f(250.f, 90.f), "Start", 60,this->font);

	//this->InitButton(100, 200, 120, 220, Color::Red, Color::Blue, Color::Yellow, 2, this->buttonText, this->button,
		//Vector2f(150.f, 50.f), "Button 2", 40, this->font);
}

void MainMenu::InitButtonExit()
{
	this->InitButton(560, 500, 580, 500, Color::Transparent, Color::Transparent, Color(39, 246, 19), 3, this->ExitGame, this->ExitButton,
		Vector2f(150.f, 80.f), "Exit", 60, this->font);

}

bool MainMenu::hover(const RenderWindow& target)
{
	return (this->button.getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition(target))));
}

bool MainMenu::hover1(const RenderWindow& target)
{
	return (this->ExitButton.getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition(target)))
		);
}



void MainMenu::setHoverColor()
{
	
	this->buttonText.setFillColor(Color(29, 117, 21));

}

void MainMenu::setHover1Color()
{
	this->ExitGame.setFillColor(Color(29, 117, 21));

}



void MainMenu::Idle()
{
	this->buttonText.setFillColor(Color(39, 246, 19));
}

void MainMenu::Idle1()
{
	this->ExitGame.setFillColor(Color(39, 246, 19));

}

bool MainMenu::ExitMainmenu(const RenderWindow &target)
{
	return (this->button.getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition(target))) 
		&& Mouse::isButtonPressed(Mouse::Left));
}



bool MainMenu::ExitGameFunction(const RenderWindow& target)
{
	return (this->ExitButton.getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition(target)))
		&& Mouse::isButtonPressed(Mouse::Left)); 
}



MainMenu::MainMenu()
{
	
	this->InitFonts();
	this->InitBackground();
	this->InitButtonStart();
	this->GameName();
	this->InitButtonExit();
	this->InitSound();
	
}

void MainMenu::PlaySound()
{
	this->sounds.setVolume(40);
	this->sounds.play();
}

void MainMenu::StopSound()
{
	this->sounds.stop();
}


MainMenu::~MainMenu()
{

}




FloatRect MainMenu::getButtonPos()
{
	return this->button.getGlobalBounds();

}




void MainMenu::render(RenderTarget* target)
{
	

	target->clear();
	
	
	

	target->draw(Background);
	target->draw(Gamename);
	
	target->draw(this->ExitButton);
	target->draw(this->ExitGame);
	

	target->draw(this->button);
	target->draw(this->buttonText);
	
	
	
	 // Draw the text first.
	// Draw the button after the text.
}



