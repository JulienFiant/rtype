/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AnimationScroller
*/

#ifndef ANIMATIONSCROLLER_HPP_
#define ANIMATIONSCROLLER_HPP_
#include "./AAnimation.hpp"

class AnimationScroller : public virtual AAnimation
{
public:
    enum Direction
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    AnimationScroller(sf::FloatRect rect, Direction dir, float speed, bool pausable);
    ~AnimationScroller();
    virtual void stop();
    virtual void pause();
    virtual void play();
    virtual sf::FloatRect get();

protected:
    float _time;
    sf::FloatRect _rect;
    float _speed;
    Direction _dir;
    bool _pausable;
    float delta;

private:
    void moveBy(float count);
};

#endif /* !ANIMATIONSCROLLER_HPP_ */
