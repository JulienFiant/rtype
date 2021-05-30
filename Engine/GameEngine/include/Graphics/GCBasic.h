/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GCBasic
*/

#ifndef GCBASIC_HPP_
#define GCBASIC_HPP_

#include "../RessourceManager.hpp"
#include "./AGraphicComponent.hpp"
#include "./GraphicEngine.h"
#include <iostream>

class GCBasic : public virtual AGraphicComponent
{
public:
    GCBasic(const std::string &name, const std::string &texture);
    GCBasic(GCBasic &entity);
    ~GCBasic(){};

    virtual bool init();
    virtual bool release();
    virtual bool reload();
    virtual bool draw();

protected:
private:
};

#endif /* !GCBASIC_HPP_ */
