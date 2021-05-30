/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** AnimationKit
*/

#ifndef ANIMATIONKIT_HPP_
#define ANIMATIONKIT_HPP_

#include "./AAnimation.hpp"
#include <map>

class AnimationKit
{
public:
    AnimationKit();
    ~AnimationKit();

    enum Anim {
        IDLE,
        MOVE_FW,
        MOVE_BW,
        MOVE_UW,
        MOVE_DW,
        TAKE_DMG,
        SHOOT,
    };

    void set(const Anim anim, AAnimation *animation, bool use = true);
    void use(const Anim anim);
    AAnimation *inUse();
    sf::FloatRect get();

protected:
    std::map<Anim, AAnimation *>::iterator _inUse;
    std::map<Anim, AAnimation *> _kit;

private:
};

#endif /* !ANIMATIONKIT_HPP_ */
