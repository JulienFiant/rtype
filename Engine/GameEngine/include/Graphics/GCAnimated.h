/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GCAnimated
*/

#ifndef GCANIMATED_HPP_
#define GCANIMATED_HPP_

#include "../RessourceManager.hpp"
#include "./AGraphicComponent.hpp"
#include "./GraphicEngine.h"
#include "./NoAnimation.h"
#include "./AnimationKit.h"

#include <iostream>

class GCAnimated : virtual public AGraphicComponent
{
public:
    GCAnimated(const std::string &name, const std::string &texture);
    GCAnimated(GCAnimated &entity);
    ~GCAnimated(){};

    virtual bool init();
    virtual bool release();
    virtual bool reload();
    virtual bool draw();

    AnimationKit _kit;

protected:
private:
};

#endif /* !GCBASIC_HPP_ */
