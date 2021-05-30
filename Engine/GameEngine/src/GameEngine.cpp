/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GameEngine
*/

#include "../include/GameEngine.hpp"

GameEngine::GameEngine()
{
}

GameEngine::~GameEngine()
{
}

bool GameEngine::init()
{
    this->_clock.restart();
    return (true);
}

bool GameEngine::release()
{
    return (true);
}

bool GameEngine::reload()
{
    return (true);
}

void GameEngine::compute()
{
    for (auto var : _entities)
    {
        std::cout << var.second << std::endl;
    }
}

sf::Clock &GameEngine::getClock()
{
    return (this->_clock);
}

float GameEngine::getTime()
{
    return (this->_clock.getElapsedTime().asSeconds());
}

GameEngine &GameEngine::get()
{
    static GameEngine engine;
    return (engine);
}