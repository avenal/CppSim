#include "MainMenuState.h"
#include <sstream>
#include <iostream>
#include "GameState.h"
#include "DEFINITIONS.h"

namespace Engine {
	MainMenuState::MainMenuState(GameDataRef data) :_data(data)
	{

	}
	void MainMenuState::Init()
	{
		this->_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));

		this->_data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
		_title.setTexture(this->_data->assets.GetTexture("Game Title"));

		this->_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);
		_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));

		_title.setPosition(300, 100);
		_playButton.setPosition(360, 300);
	}
	void MainMenuState::HandleInput()
	{
		sf::Event event;
		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			if (this->_data->input.IsSpriteClicked(_playButton, sf::Mouse::Left, _data->window))
			{
				std::cout << "Go to game screen" << ::std::endl;
				_data->machine.AddState(StateRef(new GameState(_data)), true);
			}
		}
	}
	void MainMenuState::Update(float dt)
	{
	
	}
	void MainMenuState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_title);
		this->_data->window.draw(this->_playButton);
		this->_data->window.display();
	}
}
