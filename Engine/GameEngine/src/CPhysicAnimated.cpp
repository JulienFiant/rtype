/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** CPhysicAnimated
*/

#include "../include/Graphics/CPhysicAnimated.hpp"

CPhysicAnimated::CPhysicAnimated(const std::string &name, const std::string &texture) : PhysicComponent(), GCAnimated(name, texture)
{
    PhysicComponent::init();
}

CPhysicAnimated::~CPhysicAnimated()
{
}

bool CPhysicAnimated::draw()
{
    auto change = this->compute({});
    this->_sprite.move(change.move);
    sf::FloatRect rect = _kit.get();
    if (rect.width > 0 && rect.height > 0)
        this->_sprite.setTextureRect(sf::IntRect((int)rect.left, (int)rect.top, (int)rect.width, (int)rect.height));
    GraphicEngine::get().getRWindow()->draw(_sprite);
    return (true);
}
