/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** IGraphics
*/

#ifndef IGRAPHICS_HPP_
#define IGRAPHICS_HPP_

#include <SFML/Graphics.hpp>
#include "../IEngine.hpp"

class IGraphic : public virtual IEngine
{
public:
    virtual ~IGraphic(){};

    virtual bool draw() = 0;
};

#endif /* !IGRAPHICS_HPP_ */
