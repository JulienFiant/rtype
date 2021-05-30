/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GraphicEngine
*/

#ifndef GRAPHICENGINE_HPP_
#define GRAPHICENGINE_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System/String.hpp>
#include <unordered_map>
#include <memory>
#include <algorithm>
#include "../Settings.hpp"
#include "../RessourceManager.hpp"
#include "./IGraphics.h"
#include "./SceneSfml.h"

class SceneSfml;

class GraphicEngine : public virtual IGraphic
{

public:
    GraphicEngine(const GraphicEngine&) = delete;
    GraphicEngine& operator=(const GraphicEngine&) = delete;

    virtual bool init();
    virtual bool release();
    virtual bool reload();
    virtual bool draw();

    void addScene(const std::string &name, SceneSfml *scene, bool setActive = false);
    void removeScene(const std::string &name);
    void activeScene(const std::string &name);
    bool recordEvent();
    void setHudUsage(ulong address);

    sf::RenderWindow *getRWindow() const;
    std::shared_ptr<SceneSfml> getActiveScene() const;
    sf::Clock &getClock();
    float getTime();
    const sf::Event getEvent() const;
    const ulong getHudUsage() const;

    static GraphicEngine &get();

protected:
    GraphicEngine();
    ~GraphicEngine();

    sf::String _name;
    sf::RenderWindow *_rWindow;
    sf::Event _evt;
    sf::Clock _clock;
    ulong _hudUsage;
    std::unordered_map<std::string, std::shared_ptr<SceneSfml>>::iterator _activeScene;
    std::unordered_map<std::string, std::shared_ptr<SceneSfml>> _scenes;

private:
};

#endif /* !GRAPHICENGINE_HPP_ */
