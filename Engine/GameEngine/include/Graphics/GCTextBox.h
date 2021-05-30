/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GCTextBox
*/

#ifndef GCTEXTBOX_HPP_
#define GCTEXTBOX_HPP_

#include "../RessourceManager.hpp"
#include "./AGraphicComponent.hpp"
#include "./GraphicEngine.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class GCTextBox : public virtual AGraphicComponent
{
public:
    GCTextBox(const std::string &name, const std::string &texture, const std::string &font);
    GCTextBox(GCTextBox &entity);
    ~GCTextBox(){};

    virtual bool init();
    virtual bool release();
    virtual bool reload();
    virtual bool draw();

    const std::string &getString() const;
    sf::Text &getText();

    virtual void setPos(float x, float y);
    virtual void setPos(sf::Vector2f npos);
    virtual void setScale(float x, float y);
    virtual void setScale(sf::Vector2f size);
    virtual void setRotation(float rotation);
    virtual void setRotation(sf::Vector2f rotation);


protected:
private:
    bool _active;
    int _maxChar;
    std::string _font;
    std::string _str;
    sf::Text _text;
};

#endif /* !GCTEXTBOX_HPP_ */
