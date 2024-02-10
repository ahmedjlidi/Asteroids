#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>


using namespace sf;
using namespace std;


class MainMenu
{
private:
	//Inisializers
	void InitButton(float ButtonposX, float ButtonposY, float pos_x, float pos_y, Color color, Color outline, Color fontColor, int outlineThick, Text &buttonText,
		RectangleShape &button, Vector2f ButtonSize, string text, int fontSize, Font& font);
	void InitBackground();
	void InitSound();
	Texture texture;
	Sprite Background;
	


	//variables
	RectangleShape button;
	
	Event ev;
	//text resources
	Font font;

	Font FontType;
	Text Gamename;

	

	RectangleShape ExitButton;
	Text buttonText;
	Text ExitGame;


	SoundBuffer buffer;
	Sound sounds;

public:

	//constructors and destructors
	MainMenu();
	virtual ~MainMenu();
	
	void PlaySound();
	void StopSound();
	void InitButtonStart();
	void InitButtonExit();
	void GameName();
	
	//functions
	void InitFonts();
	void render(RenderTarget* target);// render


	//button actions
	bool hover(const RenderWindow& target);
	bool hover1(const RenderWindow& target);
	void setHoverColor();
	void setHover1Color();
	void Idle();
	void Idle1();
	

	bool ExitMainmenu(const RenderWindow& target);
	bool ExitGameFunction(const RenderWindow& target);
		
	//get button corrdinates
	FloatRect getButtonPos();

};

