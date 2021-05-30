/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** NoAnimation
*/

#ifndef NOANIMATION_HPP_
#define NOANIMATION_HPP_

#include "./AAnimation.hpp"

class NoAnimation : public virtual AAnimation
{
public:
    NoAnimation(sf::FloatRect rect = {0, 0, 0, 0});
    ~NoAnimation();

    virtual void stop();
    virtual void pause();
    virtual void play();
    virtual sf::FloatRect get();
};

#endif /* !NOANIMATION_HPP_ */
