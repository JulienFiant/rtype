/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GraphicComponent
*/

#ifndef AGRAPHICCOMPONENT_HPP_
#define AGRAPHICCOMPONENT_HPP_

#include "../AInteractive.hpp"
#include "./IGraphics.h"
#include "../../SfmlTools/Math/Trigonometry.hpp"
#include <SFML/Graphics.hpp>

class AGraphicComponent : public virtual IGraphic, public virtual AInteractive
{
public:
    virtual ~AGraphicComponent(){};

    virtual const sf::Vector2f getPos() const
    {
        auto tmp = this->_sprite.getPosition();
        tmp.x -= _offset.x;
        tmp.y -= _offset.y;
        return (tmp);
    };

    virtual const sf::Vector2f &getOffset() const
    {
        return (this->_offset);
    };

    virtual const sf::Vector2f &getScale() const
    {
        return (this->_sprite.getScale());
    };

    virtual const float getRotation() const
    {
        return (this->_sprite.getRotation());
    };

    const std::string &getTexture() const
    {
        return (this->_texture);
    };

    virtual const ulong getId() { return (this->_id); };

    const std::string &getName() const
    {
        return (this->_name);
    };

    virtual const sf::FloatRect getRect() const 
    {
        return (this->_sprite.getGlobalBounds());
    };

    virtual void setPos(float x, float y)
    {
        this->_sprite.setPosition(x, y);
    };

    virtual void setPos(sf::Vector2f npos)
    {
        this->_sprite.setPosition(npos);
    };

    virtual void setOffset(float x, float y)
    {
        this->_sprite.move(x - _offset.x, y - _offset.y);
        this->_offset.x = x;
        this->_offset.y = y;
    };

    virtual void setOffset(sf::Vector2f npos)
    {
        this->_sprite.move(npos.x - _offset.x, npos.y - _offset.y);
        this->_offset = npos;
    };

    virtual void setScale(float x, float y)
    {
        this->_sprite.setScale(x, y);
    };

    virtual void setScale(sf::Vector2f scale)
    {
        this->_sprite.setScale(scale);
    };

    virtual void setRotation(float rotation)
    {
        this->_sprite.setRotation(rotation);
    };

    virtual void setRotation(sf::Vector2f rotation)
    {
        this->_sprite.setRotation(Trigonometry::fullAngle2(rotation.x, rotation.y));
    };

    virtual bool isInputLocking() { return (this->_inputLocking); };

protected:
    ulong _id;
    bool _inputLocking;
    std::string _name;
    std::string _texture;
    sf::Vector2f _offset;
    sf::Sprite _sprite;
};

#endif /* !GRAPHICCOMPONENT_HPP_ */
