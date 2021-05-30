/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GraphicEngine
*/

#include "../include/Graphics/GraphicEngine.h"

GraphicEngine::GraphicEngine()
{
}

GraphicEngine::~GraphicEngine()
{
}

bool GraphicEngine::init()
{
    auto name = new sf::String("RType");
    auto start = new SceneSfml("Start");
    this->addScene(start->getName(), start, true);
    this->_clock.restart();
    _hudUsage = 0;
    Settings::get().load();
    this->_rWindow = new sf::RenderWindow(sf::VideoMode(Settings::get().size().x, Settings::get().size().y),
                                          *name,
                                          Settings::get().style(),
                                          Settings::get().context());
    if (Settings::get().fpsLimit())
        this->_rWindow->setFramerateLimit(Settings::get().fps());
    return (true);
}

bool GraphicEngine::release()
{
    t_R::get().release();
    return (true);
}

bool GraphicEngine::reload()
{
    auto name = new sf::String("RType");
    Settings::get().load();
    this->_rWindow = new sf::RenderWindow(sf::VideoMode(Settings::get().size().x, Settings::get().size().y),
                                          *name,
                                          Settings::get().style(),
                                          Settings::get().context());
    if (Settings::get().fpsLimit())
        this->_rWindow->setFramerateLimit(Settings::get().fps());
    return (true);
}

bool GraphicEngine::draw()
{
    this->_rWindow->clear();
    this->_activeScene->second->draw();
    this->_rWindow->display();
    return (true);
}

void GraphicEngine::addScene(const std::string &name, SceneSfml *scene, bool setActive)
{
    this->_scenes[name] = std::shared_ptr<SceneSfml>(scene);
    if (setActive)
    {
        this->_activeScene = this->_scenes.find(name);
    }
}

void GraphicEngine::removeScene(const std::string &name)
{
    this->_scenes.erase(name);
}

void GraphicEngine::activeScene(const std::string &name)
{
    auto active = this->_scenes.find(name);
    if (active != this->_scenes.end())
        this->_activeScene = active;
}

bool GraphicEngine::recordEvent()
{
    while (GraphicEngine::get().getRWindow()->pollEvent(_evt))
    {
        if (_evt.type == sf::Event::Closed || (_evt.type == sf::Event::KeyPressed && _evt.key.code == sf::Keyboard::F4))
            GraphicEngine::get().getRWindow()->close();
        this->_activeScene->second->interact();
    }
    return (true);
}

void GraphicEngine::setHudUsage(ulong address)
{
    this->_hudUsage = address;
}

sf::RenderWindow *GraphicEngine::getRWindow() const
{
    return (this->_rWindow);
}

std::shared_ptr<SceneSfml> GraphicEngine::getActiveScene() const
{
    return (this->_activeScene->second);
}

sf::Clock &GraphicEngine::getClock()
{
    return (this->_clock);
}

float GraphicEngine::getTime()
{
    return (this->_clock.getElapsedTime().asSeconds());
}

const sf::Event GraphicEngine::getEvent() const
{
    return (this->_evt);
}

const ulong GraphicEngine::getHudUsage() const
{
    return (this->_hudUsage);
}

GraphicEngine &GraphicEngine::get()
{
    static GraphicEngine engine;
    return (engine);
}
