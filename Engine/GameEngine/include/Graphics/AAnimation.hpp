/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AAnimation
*/

#ifndef AANIMATION_HPP_
#define AANIMATION_HPP_

#include <SFML/Graphics/Rect.hpp>
#include "./GraphicEngine.h"

class AAnimation
{
public:
    enum Status
    {
        STOP,
        PLAY,
        PAUSE,
    };
    AAnimation(){};
    virtual ~AAnimation(){};

    virtual void stop() = 0;
    virtual void pause() = 0;
    virtual void play() = 0;
    virtual sf::FloatRect get() = 0;
    Status getStatus() { return (this->_status); };
    sf::FloatRect getRect() { return (this->_rect); };

    sf::FloatRect _rect;
    Status _status;
};

#endif /* !AANIMATION_HPP_ */
