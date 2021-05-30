/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GraphicEntity
*/

#include "../include/Graphics/GCBasic.h"

GCBasic::GCBasic(const std::string &name, const std::string &texture)
{
    this->_name = name;
    this->_texture = texture;
    this->_id = RessourceManager::attributeId();
    this->init();
}

GCBasic::GCBasic(GCBasic &entity)
{
    this->_name = entity._name;
    this->_texture = entity._texture;
    this->_sprite = entity._sprite;
}

bool GCBasic::init()
{
    this->_inputLocking = false;
    auto tex = t_R::get().getTexture(this->_texture);
    if (tex)
    {
        this->_sprite.setTexture(*tex);
    }
    return (true);
}

bool GCBasic::release()
{
    return (true);
}

bool GCBasic::reload()
{
    auto tex = t_R::get().getTexture(this->_name);
    if (tex)
    {
        this->_sprite.setTexture(*tex);
        return (true);
    }
    return (false);
}

bool GCBasic::draw()
{
    GraphicEngine::get().getRWindow()->draw(_sprite);
    return (true);
}
