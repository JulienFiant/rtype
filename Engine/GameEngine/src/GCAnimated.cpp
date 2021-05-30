/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GCAnimated
*/

#include "../include/Graphics/GCAnimated.h"

GCAnimated::GCAnimated(const std::string &name, const std::string &texture)
{
    this->_name = name;
    this->_texture = texture;
    this->_id = RessourceManager::attributeId();
    this->init();
}

GCAnimated::GCAnimated(GCAnimated &entity)
{
    this->_name = entity._name;
    this->_texture = entity._texture;
    this->_sprite = entity._sprite;
}

bool GCAnimated::init()
{
    this->_inputLocking = false;
    auto tex = t_R::get().getTexture(this->_texture);
    if (tex)
    {
        this->_sprite.setTexture(*tex);
    }
    return (true);
}

bool GCAnimated::release()
{
    return (true);
}

bool GCAnimated::reload()
{
    auto tex = t_R::get().getTexture(this->_name);
    if (tex)
    {
        this->_sprite.setTexture(*tex);
        return (true);
    }
    return (false);
}

bool GCAnimated::draw()
{
    sf::FloatRect rect = _kit.get();
    if (rect.width > 0 && rect.height > 0)
        this->_sprite.setTextureRect(sf::IntRect((int)rect.left, (int)rect.top, (int)rect.width, (int)rect.height));
    GraphicEngine::get().getRWindow()->draw(_sprite);
    return (true);
}
