/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GameEngine
*/

#ifndef GAMEENGINE_HPP_
#define GAMEENGINE_HPP_

#include <unordered_map>
#include <memory>
#include <algorithm>
#include "./RessourceManager.hpp"
#include "./IEngine.hpp"

class GameEngine : public virtual IEngine
{
public:

    GameEngine(const GameEngine&) = delete;
    GameEngine& operator=(const GameEngine&) = delete;

    virtual bool init();
    virtual bool release();
    virtual bool reload();

    void addEntity(ulong id, int);
    bool removeEntity(ulong id);

    void compute();
    sf::Clock &getClock();
    float getTime();

    static GameEngine &get();

protected:
private:
    GameEngine();
    ~GameEngine();

    sf::Clock _clock;
    std::unordered_map<ulong, int> _entities;
};

#endif /* !GAMEENGINE_HPP_ */
