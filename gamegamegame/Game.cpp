#include "Game.h"

//void Game::Game()
//{

//}

void Game::runGame()
{
	this->initWorld();
	//this->render();
}

void Game::initWorld()
{
	this->worldBackgroundTexture.loadFromFile("Textures/PA9_BG.png");
	this->worldBackground.setTexture(this->worldBackgroundTexture);
}

void Game::render()
{
	//this->window->clear();

	// draw background
	this->renderWorld();

	// render borders and stuff

}

void Game::renderWorld()
{
	this->window->draw(this->worldBackground);
}
