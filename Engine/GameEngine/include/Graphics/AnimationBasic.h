/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Animation
*/

#ifndef ANIMATIONBASIC_HPP_
#define ANIMATIONBASIC_HPP_

#include "./AAnimation.hpp"

class AnimationBasic : public virtual AAnimation
{
public:
    enum Direction
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    AnimationBasic(sf::FloatRect rect, Direction dir, uint count, float duration, bool loop, int margin = 0);
    ~AnimationBasic();

    virtual void stop();
    virtual void pause();
    virtual void play();
    virtual sf::FloatRect get();

protected:
    float _time;
    float _fps;
    uint _count;
    int _margin;
    bool _loop;
    Direction _dir;
    uint i;
    float delta;

private:
    void moveBy(int count);
};

#endif /* !ANIMATION_HPP_ */
